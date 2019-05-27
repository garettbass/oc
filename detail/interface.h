#pragma once
#include "message.h"

//------------------------------------------------------------------------------

#define _oc_interface(CLASS, /*SYMBOLS*/...)\
        __oc_interface(CLASS,\
            cls(Class,  class),\
            cls(CLASS*, new),\
            cls(CLASS*, alloc),\
            obj(void,   dealloc),\
            obj(CLASS*, init),\
            obj(CLASS*, copy),\
            obj(CLASS*, autorelease),\
            obj(void,   release),\
            obj(CLASS*, retain),\
            obj(size_t, retainCount),\
            __VA_ARGS__)
#define __oc_interface(CLASS, /*SYMBOLS*/...)\
        oc_class(CLASS)\
        static Class CLASS##_class = NULL;\
        _oc_interface_symbol_declarations(CLASS, __VA_ARGS__)\
        _oc_extern_c_begin\
        __attribute__((constructor))\
        static inline void\
        _oc_interface_initializer_##CLASS(void) {\
            _oc_interface_initializer(&CLASS##_class, #CLASS);\
            _oc_interface_symbol_initializers(CLASS, __VA_ARGS__)\
        }\
        _oc_extern_c_end

        _oc_extern_c_begin
        static inline void
        _oc_interface_initializer(Class* pcls, const char name[]) {
            assert(*pcls == NULL);
            *pcls = objc_getClass(name);
        }
        _oc_extern_c_end

//------------------------------------------------------------------------------

#define _oc_interface_symbol_suffix(SYMBOL)\
        _oc_defer(_oc_concat_2(_oc_interface_symbol_suffix,_##SYMBOL))
#define _oc_interface_symbol_suffix_cls(...) cls
#define _oc_interface_symbol_suffix_obj(...) obj
#define _oc_interface_symbol_suffix_         end

//------------------------------------------------------------------------------

#define _oc_interface_symbol_params(SYMBOL)\
        _oc_defer(_oc_concat_2(_oc_interface_symbol_params,_##SYMBOL))
#define _oc_interface_symbol_params_cls(...) __VA_ARGS__
#define _oc_interface_symbol_params_obj(...) __VA_ARGS__
#define _oc_interface_symbol_params_(...)    __VA_ARGS__

//------------------------------------------------------------------------------

#define _oc_interface_symbol_declarations(CLASS, /*SYMBOLS*/...)\
        _oc_map1(_oc_interface_symbol_declaration, CLASS, __VA_ARGS__)
#define _oc_interface_symbol_declaration(CLASS, SYMBOL)\
        __oc_interface_symbol_declaration_(CLASS,\
            _oc_interface_symbol_suffix(SYMBOL),\
            _oc_interface_symbol_params(SYMBOL))
#define __oc_interface_symbol_declaration_(CLASS, SUFFIX, /*PARAMS*/...)\
        _oc_defer(_oc_concat_2(__oc_interface_symbol_declaration_,SUFFIX))\
            (CLASS, __VA_ARGS__)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define __oc_interface_symbol_declaration_cls(/*CLASS, RESULT,*/...)\
        ___oc_interface_symbol_declaration_cls(__VA_ARGS__)
#define ___oc_interface_symbol_declaration_cls(CLASS, RESULT, ...)\
        _oc_msg_sel_declaration(CLASS, __VA_ARGS__)\
        _oc_msg_declaration(CLASS, RESULT, Class, __VA_ARGS__)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define __oc_interface_symbol_declaration_obj(/*CLASS, RESULT,*/...)\
        ___oc_interface_symbol_declaration_obj(__VA_ARGS__)
#define ___oc_interface_symbol_declaration_obj(CLASS, RESULT, ...)\
        _oc_msg_sel_declaration(CLASS, __VA_ARGS__)\
        _oc_msg_declaration(CLASS, RESULT, CLASS*, __VA_ARGS__)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define __oc_interface_symbol_declaration_end(...)

//------------------------------------------------------------------------------

#define _oc_interface_symbol_initializers(CLASS, /*SYMBOLS*/...)\
        _oc_map1(_oc_interface_symbol_initializer, CLASS, __VA_ARGS__)
#define _oc_interface_symbol_initializer(CLASS, SYMBOL)\
        _oc_interface_symbol_initializer_(CLASS,\
            _oc_interface_symbol_suffix(SYMBOL),\
            _oc_interface_symbol_params(SYMBOL))
#define _oc_interface_symbol_initializer_(CLASS, SUFFIX, /*PARAMS*/...)\
        _oc_defer(_oc_concat_2(_oc_interface_symbol_initializer_,SUFFIX))\
            (CLASS, __VA_ARGS__)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define _oc_interface_symbol_initializer_cls(/*CLASS, RESULT,*/...)\
        __oc_interface_symbol_initializer_cls(__VA_ARGS__)
#define __oc_interface_symbol_initializer_cls(CLASS, RESULT, ...)\
        _oc_msg_sel_initializer(CLASS, ClassMethod, __VA_ARGS__);

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define _oc_interface_symbol_initializer_obj(/*CLASS, RESULT,*/...)\
        __oc_interface_symbol_initializer_obj(__VA_ARGS__)
#define __oc_interface_symbol_initializer_obj(CLASS, RESULT, ...)\
        _oc_msg_sel_initializer(CLASS, InstanceMethod, __VA_ARGS__);

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define _oc_interface_symbol_initializer_end(...)

//------------------------------------------------------------------------------
