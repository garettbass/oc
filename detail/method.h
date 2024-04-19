#pragma once
#include "message.h"

//------------------------------------------------------------------------------

#define _oc_method(RESULT, CLASS, /*PARAMS*/...)\
        static RESULT\
        _oc_msg_method(CLASS, __VA_ARGS__)\
        _oc_msg_params(_oc_msg_self_t(CLASS, __VA_ARGS__), __VA_ARGS__)

//------------------------------------------------------------------------------

#define _oc_method_declaration(CLASS, TSELF, RESULT, /*PARAMS*/...)\
        typedef TSELF _oc_msg_self_t(CLASS, __VA_ARGS__);\
        static RESULT\
        _oc_msg_method(CLASS, __VA_ARGS__)\
        _oc_msg_params(_oc_msg_self_t(CLASS, __VA_ARGS__), __VA_ARGS__);

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define _oc_method_initializer(CLASS, METHOD_TYPE, RESULT, /*PARAMS*/...)\
        __oc_method_initializer(\
            (objc_imp)_oc_msg_method(CLASS, __VA_ARGS__),\
            _oc_msg_string(CLASS, __VA_ARGS__),\
            CLASS##_class,\
            class_add##METHOD_TYPE);

        _oc_extern_c_begin
        static inline bool
        class_addClassMethod(objc_class* cls, objc_selector* sel, objc_imp imp) {
            objc_class* const mcls = object_getClass(cls);
            return class_addMethod(mcls, sel, imp, "v");
        }

        static inline bool
        class_addInstanceMethod(objc_class* cls, objc_selector* sel, objc_imp imp) {
            return class_addMethod(cls, sel, imp, "v");
        }

        static inline void
        __oc_method_initializer(
            const objc_imp   imp,
            const char  msg_string[],
            objc_class* const cls,
            bool (*addMethod)(objc_class*, objc_selector*, objc_imp)
        ) {
            assert(imp);
            objc_selector* const sel = sel_getUid(msg_string);
            const bool added = addMethod(cls, sel, imp);
            assert(added);(void)added;
        }
        _oc_extern_c_end

//------------------------------------------------------------------------------
