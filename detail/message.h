#pragma once
#include "../oc.h"

//------------------------------------------------------------------------------

#if defined(__x86_64__)
    enum { _OC_MSG_SEND_RESULT_SIZE = (sizeof(void*) * 2)  }; // rax, rdx
#elif defined(__i386__)
    enum { _OC_MSG_SEND_RESULT_SIZE = (sizeof(void*) * 2)  }; // eax, edx
#elif defined(__aarch64__)
    enum { _OC_MSG_SEND_RESULT_SIZE = (sizeof(void*) * 8)  }; // r0..r8
#elif defined(__arm__)
    enum { _OC_MSG_SEND_RESULT_SIZE = (sizeof(void*) * 1)  }; // r0
#else
    #error "unrecognized architecture"
#endif

//------------------------------------------------------------------------------

#ifdef __cplusplus

    template<typename T>
    struct _oc_msg_send_for {
        static void* get() {
            return
                (sizeof(T) <= _OC_MSG_SEND_RESULT_SIZE)
                ? (void*)objc_msgSend
                : (void*)objc_msgSend_stret;
        }
    };

    template<>
    struct _oc_msg_send_for<void> {
        static void* get() { return (void*)objc_msgSend; }
    };

    template<>
    struct _oc_msg_send_for<float> {
        static void* get() { return (void*)objc_msgSend_fpret; }
    };

    template<>
    struct _oc_msg_send_for<double> {
        static void* get() { return (void*)objc_msgSend_fpret; }
    };

    template<>
    struct _oc_msg_send_for<long double> {
        static void* get() { return (void*)objc_msgSend_fpret; }
    };

    #define _oc_msg_send_f(T) _oc_msg_send_for<T>::get()

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    template<typename T>
    struct _oc_msg_send_super_for {
        static void* get() {
            return
                (sizeof(T) <= _OC_MSG_SEND_RESULT_SIZE)
                ? (void*)objc_msgSendSuper2
                : (void*)objc_msgSendSuper2_stret;
        }
    };

    template<>
    struct _oc_msg_send_super_for<void> {
        static void* get() { return (void*)objc_msgSendSuper2; }
    };

    template<>
    struct _oc_msg_send_super_for<float> {
        static void* get() { return (void*)objc_msgSendSuper2; }
    };

    template<>
    struct _oc_msg_send_super_for<double> {
        static void* get() { return (void*)objc_msgSendSuper2; }
    };

    template<>
    struct _oc_msg_send_super_for<long double> {
        static void* get() { return (void*)objc_msgSendSuper2; }
    };

    #define _oc_msg_send_super_f(T)\
            _oc_msg_send_super_for<T>::get()

#else // C11 -------------------------------------------------------------------

    #define _oc_sizeof_result(T)\
            sizeof(_Generic(((T*)0),\
                const void*: *((char*)0),\
                      void*: *((char*)0),\
                    default: *((T*)0)\
            ))

    #define _oc_msg_send_for_small_result(T) \
            _Generic(((T*)0), \
                const double*: objc_msgSend_fpret, \
                      double*: objc_msgSend_fpret, \
                 const float*: objc_msgSend_fpret, \
                       float*: objc_msgSend_fpret, \
                  const void*: objc_msgSend, \
                        void*: objc_msgSend, \
                      default: objc_msgSend)

    #define _oc_msg_send_for_large_result(T) \
            _Generic(((T*)0), \
                const double*: objc_msgSend_fpret, \
                      double*: objc_msgSend_fpret, \
                 const float*: objc_msgSend_fpret, \
                       float*: objc_msgSend_fpret, \
                      default: objc_msgSend_stret)

    #define _oc_msg_send_f(T) \
            ((_oc_sizeof_result(T) <= _OC_MSG_SEND_RESULT_SIZE) \
            ? (void*)_oc_msg_send_for_small_result(T) \
            : (void*)_oc_msg_send_for_large_result(T))

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    #define _oc_msg_send_super_for_small_result(T) \
            objc_msgSendSuper2

    #define _oc_msg_send_super_for_large_result(T) \
            _Generic(((T*)0), \
                const double*: objc_msgSendSuper2, \
                      double*: objc_msgSendSuper2, \
                 const float*: objc_msgSendSuper2, \
                       float*: objc_msgSendSuper2, \
                      default: objc_msgSendSuper2_stret)

    #define _oc_msg_send_super_f(T) \
            ((_oc_sizeof_result(T) <= _OC_MSG_SEND_RESULT_SIZE) \
            ? (void*)_oc_msg_send_super_for_small_result(T) \
            : (void*)_oc_msg_send_super_for_large_result(T))

#endif // __cplusplus / C11

//------------------------------------------------------------------------------

typedef struct objc_super2 {
    id    receiver;
    Class receiver_class;
    #ifdef __cplusplus
    objc_super2(id obj, Class obj_class)
    : receiver(obj)
    , receiver_class(obj_class) {}
    operator objc_super2*() { return this; }
    #endif
} objc_super2;

#ifdef __cplusplus
    #define objc_super2(SELF) (objc_super2(SELF, object_getClass(SELF)))
#else
    #define objc_super2(SELF) &((objc_super2){SELF, object_getClass(SELF)})
#endif

//------------------------------------------------------------------------------

#define oc_msg_check(SELF, CLASS, /*PARAMS*/...)\
        _oc_msg_check(SELF, oc_sel(CLASS, __VA_ARGS__))

        _oc_extern_c_begin
        static inline id
        _oc_msg_check(id const self, SEL const sel) {
            Class cls = object_getClass(self);
            Method method = class_getInstanceMethod(cls, sel);
            if (method == NULL) {
                const char* const classname = class_getName(cls);
                const char* const methodname = sel_getName(sel);
                printf("method not found: %s.%s\n", classname, methodname);
                unsigned methodCount = 0;
                Method* methodList = class_copyMethodList(cls, &methodCount);
                printf("candidates: %u\n", methodCount);
                for (int i = 0; i < methodCount; ++i) {
                    SEL sel = method_getName(methodList[i]);
                    const char* const methodname = sel_getName(sel);
                    fputs("    ", stdout);
                    fputs(methodname, stdout);
                    fputc('\n', stdout);
                }
                free(methodList);
                exit(1);
            }
            return self;
        }
        _oc_extern_c_end

//------------------------------------------------------------------------------

#define _oc_msg_send(SELF, CLASS, /*PARAMS*/...)\
        __oc_msg_send(\
            oc_msg_check(SELF, CLASS, __VA_ARGS__),\
            _oc_msg_result_t(CLASS, __VA_ARGS__),\
            _oc_msg_send_t(CLASS, __VA_ARGS__),\
            _oc_msg_args(CLASS, __VA_ARGS__))
#define __oc_msg_send(SELF, RESULT_T, MSG_SEND_T, /*ARGS*/...)\
        ((MSG_SEND_T)_oc_msg_send_f(RESULT_T))(SELF, __VA_ARGS__)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define _oc_msg_send_super(CLASS, /*PARAMS*/...)\
        __oc_msg_send_super(CLASS,\
            _oc_msg_result_t(CLASS, __VA_ARGS__),\
            _oc_msg_super_t(CLASS, __VA_ARGS__),\
            _oc_msg_args(CLASS, __VA_ARGS__))
#define __oc_msg_send_super(CLASS, RESULT_T, MSG_SUPER_T, /*ARGS*/...)\
        ((MSG_SUPER_T)_oc_msg_send_super_f(RESULT_T))\
            (objc_super2(self), __VA_ARGS__)

//------------------------------------------------------------------------------

#define _oc_msg_params(TSELF, /*PARAMS*/...)\
        _oc_concat_2(_oc_msg_params_,_oc_va_len(__VA_ARGS__))\
            (TSELF, __VA_ARGS__)
#define _oc_msg_params_1(TSELF, P1)\
        (TSELF self, SEL cmd)
#define _oc_msg_params_2(TSELF, P1,T1)\
        (TSELF self, SEL cmd, T1 P1)
#define _oc_msg_params_4(TSELF, P1,T1, P2,T2)\
        (TSELF self, SEL cmd, T1 P1, T2 P2)
#define _oc_msg_params_6(TSELF, P1,T1, P2,T2, P3,T3)\
        (TSELF self, SEL cmd, T1 P1, T2 P2, T3 P3)
#define _oc_msg_params_8(TSELF, P1,T1, P2,T2, P3,T3, P4,T4)\
        (TSELF self, SEL cmd, T1 P1, T2 P2, T3 P3, T4 P4)
#define _oc_msg_params_10(TSELF, P1,T1, P2,T2, P3,T3, P4,T4, P5,T5)\
        (TSELF self, SEL cmd, T1 P1, T2 P2, T3 P3, T4 P4, T5 P5)
#define _oc_msg_params_12(TSELF, P1,T1, P2,T2, P3,T3, P4,T4, P5,T5, P6,T6)\
        (TSELF self, SEL cmd, T1 P1, T2 P2, T3 P3, T4 P4, T5 P5, T6 P6)
#define _oc_msg_params_14(TSELF, P1,T1, P2,T2, P3,T3, P4,T4, P5,T5, P6,T6, P7,T7)\
        (TSELF self, SEL cmd, T1 P1, T2 P2, T3 P3, T4 P4, T5 P5, T6 P6, T7 P7)
#define _oc_msg_params_16(TSELF, P1,T1, P2,T2, P3,T3, P4,T4, P5,T5, P6,T6, P7,T7, P8,T8)\
        (TSELF self, SEL cmd, T1 P1, T2 P2, T3 P3, T4 P4, T5 P5, T6 P6, T7 P7, T8 P8)
#define _oc_msg_params_18(TSELF, P1,T1, P2,T2, P3,T3, P4,T4, P5,T5, P6,T6, P7,T7, P8,T8, P9,T9)\
        (TSELF self, SEL cmd, T1 P1, T2 P2, T3 P3, T4 P4, T5 P5, T6 P6, T7 P7, T8 P8, T9 P9)

//------------------------------------------------------------------------------

#define _oc_msg_args(CLASS, /*PARAMS*/...)\
        _oc_concat_2(__oc_msg_args_,_oc_va_len(__VA_ARGS__))\
            (CLASS, __VA_ARGS__)
#define __oc_msg_args_1(CLASS, P1)\
        oc_sel(CLASS,P1)
#define __oc_msg_args_2(CLASS, P1,A1)\
        oc_sel(CLASS,P1,A1), A1
#define __oc_msg_args_4(CLASS, P1,A1, P2,A2)\
        oc_sel(CLASS,P1,A1,P2,A2), A1, A2
#define __oc_msg_args_6(CLASS, P1,A1, P2,A2, P3,A3)\
        oc_sel(CLASS,P1,A1,P2,A2,P3,A3), A1, A2, A3
#define __oc_msg_args_8(CLASS, P1,A1, P2,A2, P3,A3, P4,A4)\
        oc_sel(CLASS,P1,A1,P2,A2,P3,A3,P4,A4), A1, A2, A3, A4
#define __oc_msg_args_10(CLASS, P1,A1, P2,A2, P3,A3, P4,A4, P5,A5)\
        oc_sel(CLASS,P1,A1,P2,A2,P3,A3,P4,A4,P5,A5), A1, A2, A3, A4, A5
#define __oc_msg_args_12(CLASS, P1,A1, P2,A2, P3,A3, P4,A4, P5,A5, P6,A6)\
        oc_sel(CLASS,P1,A1,P2,A2,P3,A3,P4,A4,P5,A5,P6,A6), A1, A2, A3, A4, A5, A6
#define __oc_msg_args_14(CLASS, P1,A1, P2,A2, P3,A3, P4,A4, P5,A5, P6,A6, P7,A7)\
        oc_sel(CLASS,P1,A1,P2,A2,P3,A3,P4,A4,P5,A5,P6,A6,P7,A7), A1, A2, A3, A4, A5, A6, A7
#define __oc_msg_args_16(CLASS, P1,A1, P2,A2, P3,A3, P4,A4, P5,A5, P6,A6, P7,A7, P8,A8)\
        oc_sel(CLASS,P1,A1,P2,A2,P3,A3,P4,A4,P5,A5,P6,A6,P7,A7,P8,A8), A1, A2, A3, A4, A5, A6, A7, A8
#define __oc_msg_args_18(CLASS, P1,A1, P2,A2, P3,A3, P4,A4, P5,A5, P6,A6, P7,A7, P8,A8, P9,A9)\
        oc_sel(CLASS,P1,A1,P2,A2,P3,A3,P4,A4,P5,A5,P6,A6,P7,A7,P8,A8,P9,A9), A1, A2, A3, A4, A5, A6, A7, A8, A9

//------------------------------------------------------------------------------

#define _oc_msg_string(CLASS, /*PARAMS*/...)\
        _oc_concat_2(_oc_msg_string_,_oc_va_len(__VA_ARGS__))\
            (CLASS, __VA_ARGS__)
#define _oc_msg_string_1(CLASS, P1)\
        _oc_quote(P1)
#define _oc_msg_string_2(CLASS, P1,T1)\
        _oc_quote(P1:)
#define _oc_msg_string_4(CLASS, P1,T1, P2,T2)\
        _oc_quote(P1:P2:)
#define _oc_msg_string_6(CLASS, P1,T1, P2,T2, P3,T3)\
        _oc_quote(P1:P2:P3:)
#define _oc_msg_string_8(CLASS, P1,T1, P2,T2, P3,T3, P4,T4)\
        _oc_quote(P1:P2:P3:P4:)
#define _oc_msg_string_10(CLASS, P1,T1, P2,T2, P3,T3, P4,T4, P5,T5)\
        _oc_quote(P1:P2:P3:P4:P5:)
#define _oc_msg_string_12(CLASS, P1,T1, P2,T2, P3,T3, P4,T4, P5,T5, P6,T6)\
        _oc_quote(P1:P2:P3:P4:P5:P6:)
#define _oc_msg_string_14(CLASS, P1,T1, P2,T2, P3,T3, P4,T4, P5,T5, P6,T6, P7,T7)\
        _oc_quote(P1:P2:P3:P4:P5:P6:P7:)
#define _oc_msg_string_16(CLASS, P1,T1, P2,T2, P3,T3, P4,T4, P5,T5, P6,T6, P7,T7, P8,T8)\
        _oc_quote(P1:P2:P3:P4:P5:P6:P7:P8:)
#define _oc_msg_string_18(CLASS, P1,T1, P2,T2, P3,T3, P4,T4, P5,T5, P6,T6, P7,T7, P8,T8, P9,T9)\
        _oc_quote(P1:P2:P3:P4:P5:P6:P7:P8:P9)

//------------------------------------------------------------------------------

#define _oc_msg_identifier(PREFIX, CLASS, /*PARAMS*/...)\
        _oc_concat_2(_oc_msg_identifier_,_oc_va_len(__VA_ARGS__))\
            (PREFIX, CLASS, __VA_ARGS__)
#define _oc_msg_identifier_1(PREFIX, CLASS, P1)\
        PREFIX##CLASS##_##P1
#define _oc_msg_identifier_2(PREFIX, CLASS, P1,T1)\
        PREFIX##CLASS##_##P1##_
#define _oc_msg_identifier_4(PREFIX, CLASS, P1,T1, P2,T2)\
        PREFIX##CLASS##_##P1##_##P2##_
#define _oc_msg_identifier_6(PREFIX, CLASS, P1,T1, P2,T2, P3,T3)\
        PREFIX##CLASS##_##P1##_##P2##_##P3##_
#define _oc_msg_identifier_8(PREFIX, CLASS, P1,T1, P2,T2, P3,T3, P4,T4)\
        PREFIX##CLASS##_##P1##_##P2##_##P3##_##P4##_
#define _oc_msg_identifier_10(PREFIX, CLASS, P1,T1, P2,T2, P3,T3, P4,T4, P5,T5)\
        PREFIX##CLASS##_##P1##_##P2##_##P3##_##P4##_##P5##_
#define _oc_msg_identifier_12(PREFIX, CLASS, P1,T1, P2,T2, P3,T3, P4,T4, P5,T5, P6,T6)\
        PREFIX##CLASS##_##P1##_##P2##_##P3##_##P4##_##P5##_##P6##_
#define _oc_msg_identifier_14(PREFIX, CLASS, P1,T1, P2,T2, P3,T3, P4,T4, P5,T5, P6,T6, P7,T7)\
        PREFIX##CLASS##_##P1##_##P2##_##P3##_##P4##_##P5##_##P6##_##P7##_
#define _oc_msg_identifier_16(PREFIX, CLASS, P1,T1, P2,T2, P3,T3, P4,T4, P5,T5, P6,T6, P7,T7, P8,T8)\
        PREFIX##CLASS##_##P1##_##P2##_##P3##_##P4##_##P5##_##P6##_##P7##_##P8##_
#define _oc_msg_identifier_18(PREFIX, CLASS, P1,T1, P2,T2, P3,T3, P4,T4, P5,T5, P6,T6, P7,T7, P8,T8, P9,T9)\
        PREFIX##CLASS##_##P1##_##P2##_##P3##_##P4##_##P5##_##P6##_##P7##_##P8##_##P9##_

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define _oc_msg_send_t(CLASS, /*PARAMS*/...)\
        _oc_msg_identifier(_oc_msg_send_t_, CLASS, __VA_ARGS__)

#define _oc_msg_super_t(CLASS, /*PARAMS*/...)\
        _oc_msg_identifier(_oc_msg_super_t_, CLASS, __VA_ARGS__)

#define _oc_msg_result_t(CLASS, /*PARAMS*/...)\
        _oc_msg_identifier(_oc_msg_result_t_, CLASS, __VA_ARGS__)

#define _oc_msg_self_t(CLASS, /*PARAMS*/...)\
        _oc_msg_identifier(_oc_msg_self_t_, CLASS, __VA_ARGS__)

#define oc_sel(CLASS, /*PARAMS*/...)\
        _oc_msg_identifier(oc_sel_, CLASS, __VA_ARGS__)

#define _oc_msg_method(CLASS, /*PARAMS*/...)\
        _oc_msg_identifier(_oc_msg_method_, CLASS, __VA_ARGS__)

//------------------------------------------------------------------------------

#define _oc_msg_sel_declaration(CLASS, /*PARAMS*/...)\
        static SEL oc_sel(CLASS, __VA_ARGS__) = NULL;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define _oc_msg_sel_initializer(CLASS, METHOD_TYPE, /*PARAMS*/...)\
        __oc_msg_sel_initializer(\
            &oc_sel(CLASS, __VA_ARGS__),\
            _oc_msg_string(CLASS, __VA_ARGS__),\
            CLASS##_class,\
            class_get##METHOD_TYPE);

        _oc_extern_c_begin
        static inline void
        __oc_msg_sel_initializer(
            SEL* const psel,
            const char name[],
            Class cls,
            Method (*getMethod)(Class,SEL)
        ) {
            assert(*psel == NULL);
            *psel = sel_getUid(name);
        }
        _oc_extern_c_end

//------------------------------------------------------------------------------

#define _oc_msg_declaration(CLASS, RESULT, TSELF, /*PARAMS*/...)\
        __oc_msg_declaration(RESULT,\
            _oc_msg_result_t(CLASS, __VA_ARGS__),\
            _oc_msg_send_t(CLASS, __VA_ARGS__),\
            _oc_msg_params(TSELF, __VA_ARGS__),\
            _oc_msg_super_t(CLASS, __VA_ARGS__),\
            _oc_msg_params(objc_super2*, __VA_ARGS__))
#define __oc_msg_declaration(\
        RESULT, RESULT_T,\
        MSG_SEND_T, MSG_SEND_PARAMS,\
        MSG_SEND_SUPER_T, MSG_SEND_SUPER_PARAMS)\
        typedef RESULT RESULT_T;\
        typedef RESULT (*MSG_SEND_T)MSG_SEND_PARAMS;\
        typedef RESULT (*MSG_SEND_SUPER_T)MSG_SEND_SUPER_PARAMS;\
        /**/
