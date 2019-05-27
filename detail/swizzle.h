#pragma once
#include "message.h"

//------------------------------------------------------------------------------

typedef void* (*_oc_msg_swizzle_imp)(IMP, void*, SEL, ...);

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define _oc_swizzle_prefix(CLASS, /*PARAMS*/...)\
        _oc_msg_identifier(_oc_swizzle_, CLASS, __VA_ARGS__)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define _oc_swizzle_args(CLASS, /*PARAMS*/...)\
        _oc_concat_2(__oc_swizzle_args_,_oc_va_len(__VA_ARGS__))\
            (CLASS, __VA_ARGS__)
#define __oc_swizzle_args_1(CLASS, P1)\
        oc_sel(CLASS,P1)
#define __oc_swizzle_args_2(CLASS, P1,T1)\
        oc_sel(CLASS,P1,T1), P1
#define __oc_swizzle_args_4(CLASS, P1,T1, P2,T2)\
        oc_sel(CLASS,P1,T1,P2,T2), P1, P2
#define __oc_swizzle_args_6(CLASS, P1,T1, P2,T2, P3,T3)\
        oc_sel(CLASS,P1,T1,P2,T2,P3,T3), P1, P2, P3
#define __oc_swizzle_args_8(CLASS, P1,T1, P2,T2, P3,T3, P4,T4)\
        oc_sel(CLASS,P1,T1,P2,T2,P3,T3,P4,T4), P1, P2, P3, P4
#define __oc_swizzle_args_10(CLASS, P1,T1, P2,T2, P3,T3, P4,T4, P5,T5)\
        oc_sel(CLASS,P1,T1,P2,T2,P3,T3,P4,T4,P5,T5), P1, P2, P3, P4, P5
#define __oc_swizzle_args_12(CLASS, P1,T1, P2,T2, P3,T3, P4,T4, P5,T5, P6,T6)\
        oc_sel(CLASS,P1,T1,P2,T2,P3,T3,P4,T4,P5,T5), P1, P2, P3, P4, P5, P6
#define __oc_swizzle_args_14(CLASS, P1,T1, P2,T2, P3,T3, P4,T4, P5,T5, P6,T6, P7,T7)\
        oc_sel(CLASS,P1,T1,P2,T2,P3,T3,P4,T4,P5,T5), P1, P2, P3, P4, P5, P6, P7
#define __oc_swizzle_args_16(CLASS, P1,T1, P2,T2, P3,T3, P4,T4, P5,T5, P6,T6, P7,T7, P8,T8)\
        oc_sel(CLASS,P1,T1,P2,T2,P3,T3,P4,T4,P5,T5), P1, P2, P3, P4, P5, P6, P7, P8

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define _oc_msg_swizzle(RESULT, CLASS, TSELF, METHOD_TYPE, /*PARAMS*/...)\
        __oc_msg_swizzle(\
            RESULT,\
            CLASS,\
            METHOD_TYPE,\
            _oc_msg_send_t(CLASS, __VA_ARGS__),\
            _oc_concat_3(_oc_swizzle_prefix(CLASS, __VA_ARGS__),_,__COUNTER__),\
            oc_sel(CLASS, __VA_ARGS__),\
            _oc_msg_params(TSELF, __VA_ARGS__),\
            _oc_swizzle_args(CLASS, __VA_ARGS__))
#define __oc_msg_swizzle(RESULT, CLASS, METHOD_TYPE, MSG_SEND_T, PREFIX, MSG_SEL, PARAMS, /*ARGS*/...)\
        ___oc_msg_swizzle(RESULT, CLASS, METHOD_TYPE, MSG_SEND_T, PREFIX, MSG_SEL, PARAMS, __VA_ARGS__)
#define ___oc_msg_swizzle(RESULT, CLASS, METHOD_TYPE, MSG_SEND_T, PREFIX, MSG_SEL, PARAMS, /*ARGS*/...)\
        _oc_extern_c_begin\
        static inline RESULT PREFIX##_callback(MSG_SEND_T imp, _oc_unpack(PARAMS));\
        static MSG_SEND_T PREFIX##_imp = NULL;\
        static void* PREFIX##_swizzle_imp PARAMS {\
            return ((_oc_msg_swizzle_imp)PREFIX##_callback)((IMP)PREFIX##_imp, self, __VA_ARGS__);\
        }\
        __attribute__((constructor))\
        static inline void\
        PREFIX##_initializer(void) {\
            PREFIX##_imp = (MSG_SEND_T)__oc_msg_swizzle_initializer(\
                CLASS##_class,\
                MSG_SEL,\
                class_get##METHOD_TYPE,\
                (IMP)PREFIX##_swizzle_imp);\
        }\
        _oc_extern_c_end\
        static inline RESULT PREFIX##_callback(MSG_SEND_T imp, _oc_unpack(PARAMS))

        _oc_extern_c_begin
        static inline IMP
        __oc_msg_swizzle_initializer(
            Class cls,
            SEL const sel,
            Method (*getMethod)(Class,SEL),
            IMP const imp
        ) {
            Method const method = getMethod(cls, sel);
            assert(method);
            return method_setImplementation(method, imp);
        }
        _oc_extern_c_end

//------------------------------------------------------------------------------
