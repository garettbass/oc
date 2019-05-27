#pragma once
#include "message.h"

//------------------------------------------------------------------------------

#define _oc_implementation(CLASS, SUPERCLASS, /*SYMBOLS*/...)\
        __oc_implementation(CLASS, SUPERCLASS, __VA_ARGS__)
#define __oc_implementation(CLASS, SUPERCLASS, /*SYMBOLS*/...)\
        _oc_implementation_symbol_declarations(CLASS, __VA_ARGS__)\
        _oc_extern_c_begin\
        __attribute__((constructor)) static inline void\
        _oc_implementation_initializer_##CLASS(void) {\
            const Class super = SUPERCLASS##_class;\
            _oc_implementation_initializer(&CLASS##_class, super, #CLASS);\
            _oc_implementation_symbol_initializers(CLASS, __VA_ARGS__)\
            objc_registerClassPair(CLASS##_class);\
        }\
        _oc_extern_c_end

        _oc_extern_c_begin
        static inline void
        _oc_implementation_initializer(Class* pcls, Class super, const char name[]) {
            assert(super);
            assert(*pcls == NULL);
            *pcls = objc_allocateClassPair(super, name, 0);
        }
        _oc_extern_c_end

//------------------------------------------------------------------------------

#define _oc_implementation_symbol_suffix(SYMBOL)\
        _oc_defer(_oc_concat_2(_oc_implementation_symbol_suffix,_##SYMBOL))
#define _oc_implementation_symbol_suffix_var(...) var
#define _oc_implementation_symbol_suffix_cls(...) cls
#define _oc_implementation_symbol_suffix_obj(...) obj
#define _oc_implementation_symbol_suffix_         end

//------------------------------------------------------------------------------

#define _oc_implementation_symbol_params(SYMBOL)\
        _oc_defer(_oc_concat_2(_oc_implementation_symbol_params,_##SYMBOL))
#define _oc_implementation_symbol_params_var(...) __VA_ARGS__
#define _oc_implementation_symbol_params_cls(...) __VA_ARGS__
#define _oc_implementation_symbol_params_obj(...) __VA_ARGS__
#define _oc_implementation_symbol_params_(...)    __VA_ARGS__

//------------------------------------------------------------------------------

#define _oc_implementation_symbol_declarations(CLASS, /*SYMBOLS*/...)\
        _oc_map1(_oc_implementation_symbol_declaration, CLASS, __VA_ARGS__)
#define _oc_implementation_symbol_declaration(CLASS, SYMBOL)\
        __oc_implementation_symbol_declaration_(CLASS,\
            _oc_implementation_symbol_suffix(SYMBOL),\
            _oc_implementation_symbol_params(SYMBOL))
#define __oc_implementation_symbol_declaration_(CLASS, SUFFIX, /*PARAMS*/...)\
        _oc_defer(_oc_concat_2(__oc_implementation_symbol_declaration_,SUFFIX))\
            (CLASS, __VA_ARGS__)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define __oc_implementation_symbol_declaration_var(CLASS, TYPE, NAME)\
        _oc_var_declaration(CLASS, TYPE, NAME)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define __oc_implementation_symbol_declaration_cls(CLASS, RESULT, /*PARAMS*/...)\
        _oc_method_declaration(CLASS, Class*, RESULT, __VA_ARGS__)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define __oc_implementation_symbol_declaration_obj(CLASS, RESULT, /*PARAMS*/...)\
        _oc_method_declaration(CLASS, CLASS*, RESULT, __VA_ARGS__)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define __oc_implementation_symbol_declaration_end(...) /**/

//------------------------------------------------------------------------------

#define _oc_implementation_symbol_initializers(CLASS, /*SYMBOLS*/...)\
        _oc_map1(_oc_implementation_symbol_initializer, CLASS, __VA_ARGS__)
#define _oc_implementation_symbol_initializer(CLASS, SYMBOL)\
        __oc_implementation_symbol_initializer_(CLASS,\
            _oc_implementation_symbol_suffix(SYMBOL),\
            _oc_implementation_symbol_params(SYMBOL))
#define __oc_implementation_symbol_initializer_(CLASS, SUFFIX, /*PARAMS*/...)\
        _oc_defer(_oc_concat_2(__oc_implementation_symbol_initializer_,SUFFIX))\
            (CLASS, __VA_ARGS__)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define __oc_implementation_symbol_initializer_var(CLASS, TYPE, NAME)\
        _oc_var_initializer(CLASS, TYPE, NAME)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define __oc_implementation_symbol_initializer_cls(CLASS, RESULT, /*PARAMS*/...)\
        _oc_method_initializer(CLASS, ClassMethod, RESULT, __VA_ARGS__)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define __oc_implementation_symbol_initializer_obj(CLASS, RESULT, /*PARAMS*/...)\
        _oc_method_initializer(CLASS, InstanceMethod, RESULT, __VA_ARGS__)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define __oc_implementation_symbol_initializer_end(...) /**/

//------------------------------------------------------------------------------
