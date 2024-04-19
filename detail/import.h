#pragma once

//------------------------------------------------------------------------------

#define _oc_import(FRAMEWORK, /*SYMBOLS*/...)\
        _oc_symbol_declarations(__VA_ARGS__)\
        _oc_extern_c_begin\
        __attribute__((constructor)) static inline void\
        _oc_concat_2(_oc_framework_symbols_initializer_##FRAMEWORK##_,__COUNTER__)(void) {\
            extern void* dlsym(void*,const char*);\
            assert(FRAMEWORK);\
            void* const framework = FRAMEWORK;\
            _oc_symbol_initializers(__VA_ARGS__)\
        }\
        _oc_extern_c_end\
        /**/

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define _oc_symbol_declarations(/*SYMBOLS*/...)\
        _oc_map(_oc_symbol_declaration, __VA_ARGS__)

#define _oc_symbol_declaration(SYMBOL)\
        _oc_defer(_oc_concat_2(_oc_symbol_declaration,_##SYMBOL))

#define _oc_symbol_declaration_function(RESULT, NAME, PARAMS)\
        typedef RESULT (*NAME##_t)PARAMS;\
        static NAME##_t NAME = NULL;\
        /**/

#define _oc_symbol_declaration_function_alias(RESULT, ALIAS, NAME, PARAMS)\
        typedef RESULT (*ALIAS##_t)PARAMS;\
        static ALIAS##_t ALIAS = NULL;\
        /**/

#define _oc_symbol_declaration_pointer(TYPE, NAME)\
        static TYPE NAME = NULL;\
        /**/

#define _oc_symbol_declaration_

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define _oc_symbol_initializers(/*SYMBOLS*/...)\
        _oc_map(_oc_symbol_initializer, __VA_ARGS__)

#define _oc_symbol_initializer(SYMBOL)\
        _oc_defer(_oc_concat_2(_oc_symbol_initializer,_##SYMBOL))

#define _oc_symbol_initializer_function(RESULT, NAME, PARAMS)\
        assert(NAME == NULL);\
        NAME = (NAME##_t)dlsym(framework, #NAME);\
        assert(NAME);\
        /**/

#define _oc_symbol_initializer_function_alias(RESULT, ALIAS, NAME, PARAMS)\
        assert(ALIAS == NULL);\
        ALIAS = (ALIAS##_t)dlsym(framework, #NAME);\
        assert(ALIAS);\
        /**/

#define _oc_symbol_initializer_pointer(TYPE, NAME)\
        assert(NAME == NULL);\
        NAME = (TYPE)*(void**)dlsym(framework, #NAME);\
        assert(NAME);\
        /**/

#define _oc_symbol_initializer_
