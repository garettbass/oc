#pragma once

//------------------------------------------------------------------------------

#define _oc_framework(FRAMEWORK)\
        static void* FRAMEWORK = NULL;\
        _oc_extern_c_begin\
        __attribute__((constructor)) static inline void\
        _oc_framework_initializer_##FRAMEWORK(void) {\
            const char path[] = #FRAMEWORK".framework/"#FRAMEWORK;\
            __oc_framework_initializer(&FRAMEWORK, path);\
        }\
        _oc_extern_c_end

        _oc_extern_c_begin
        static inline void
        __oc_framework_initializer(void** pframework, const char path[]) {
            assert(*pframework == NULL);
            enum { RTLD_LAZY_LOCAL = 0x1 | 0x4 };
            extern void* dlopen(const char*,int);
            *pframework = dlopen(path, RTLD_LAZY_LOCAL);
            assert(*pframework);
        }
        _oc_extern_c_end

//------------------------------------------------------------------------------
