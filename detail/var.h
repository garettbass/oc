#pragma once
#include "message.h"

//------------------------------------------------------------------------------

#define _oc_var(SELF, CLASS, NAME)\
        __oc_var(SELF, _oc_var_thunk_t(CLASS, NAME), _oc_var_offset(CLASS, NAME))
#define __oc_var(SELF, THUNK_T, VAR_OFFSET)\
        (((THUNK_T)_oc_var_thunk)(SELF, VAR_OFFSET)[0])

        _oc_extern_c_begin
        static inline void*
        _oc_var_thunk(void* const self, const size_t var_offset) {
            return ((char*)self) + var_offset;
        }
        _oc_extern_c_end

//------------------------------------------------------------------------------

#define _oc_var_thunk_t(CLASS, NAME)\
        _oc_var_thunk_t_##CLASS##_##NAME

#define _oc_var_offset(CLASS, NAME)\
        _oc_var_offset_##CLASS##_##NAME

//------------------------------------------------------------------------------

#define _oc_var_declaration(CLASS, TYPE, NAME)\
        typedef TYPE* (*_oc_var_thunk_t(CLASS, NAME))(CLASS* const, const size_t);\
        static size_t _oc_var_offset(CLASS, NAME) = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define _oc_var_initializer(CLASS, TYPE, NAME)\
        __oc_var_initializer(\
            &_oc_var_offset(CLASS, NAME),\
            CLASS##_class,\
            #NAME,\
            sizeof(TYPE),\
            alignof(TYPE));

        _oc_extern_c_begin
        static inline void
        __oc_var_initializer(
            size_t*     const pvar_offset,
            objc_class* const cls,
            const char        name[],
            const size_t      size,
            const size_t      align
        ) {
            assert(*pvar_offset == 0);
            const bool added = class_addIvar(cls, name, size, align, "?");
            assert(added);(void)added;
            *pvar_offset = ivar_getOffset(class_getInstanceVariable(cls, name));
        }
        _oc_extern_c_end

//------------------------------------------------------------------------------
