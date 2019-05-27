#pragma once
#ifdef OC_H_6BD98208_07AE_43B7_98CF_8B81AD3BEABF
    #if OC_VERSION_MAJOR != 0 ||\
        OC_VERSION_MINOR != 0 ||\
        OC_VERSION_PATCH != 0
        #error "expected version 0.0.0"
    #endif
#else
#define OC_H_6BD98208_07AE_43B7_98CF_8B81AD3BEABF 100

//------------------------------------------------------------------------------

#define OC_VERSION_MAJOR 0
#define OC_VERSION_MINOR 0
#define OC_VERSION_PATCH 0
#define OC_VERSION\
        OC_VERSION_(OC_VERSION_MAJOR,OC_VERSION_MINOR,OC_VERSION_PATCH)
#define OC_VERSION_(X, Y, Z) OC_VERSION__(X, Y, Z)
#define OC_VERSION__(X, Y, Z) ("oc " #X "." #Y "." #Z "")

//------------------------------------------------------------------------------

#if __has_feature(objc_arc)
    #error "Objective-C Automatic Reference Counting is enabled"
#endif

//------------------------------------------------------------------------------

#include <assert.h>
#include <stdalign.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "detail/id.h"
#include "detail/utility.h"

//------------------------------------------------------------------------------

#ifdef __cplusplus
    #define _oc_extern_c_begin extern "C" {
    #define _oc_extern_c_end   }
#else
    #define _oc_extern_c_begin /* extern "C" { */
    #define _oc_extern_c_end   /* } */
#endif

//------------------------------------------------------------------------------

typedef struct objc_category   *Category;
typedef struct objc_class      *Class;
typedef struct objc_ivar       *Ivar;
typedef struct objc_method     *Method;
typedef struct objc_selector   *SEL;
typedef struct objc_property   *Property;
typedef struct objc_super2     objc_super2;

typedef id (*IMP)(id, SEL, ...);

//------------------------------------------------------------------------------
/*  Example:
        oc_framework(Foundation)
*/
#define oc_framework(FRAMEWORK) _oc_framework(FRAMEWORK)
#include "detail/framework.h"

//------------------------------------------------------------------------------
/*  Example:
        oc_import(
            Foundation,
            function(void,objc_release,(void*)),
            function(void,objc_retain,(void*)),
        )
*/
#define oc_import(FRAMEWORK, /*SYMBOLS*/...) _oc_import(FRAMEWORK, __VA_ARGS__)
#include "detail/import.h"

//------------------------------------------------------------------------------

oc_framework(CoreFoundation)
oc_import(
    CoreFoundation,
    function(id,          CFRetain,(void*)),
    function(void,        CFRelease,(const void*)),
    function(id,          CFAutorelease,(const void*)),
    function(signed long, CFGetRetainCount,(const void*)),
)

#define oc_retain(obj)      (CFRetain(obj))
#define oc_release(obj)     (CFRelease(obj))
#define oc_autorelease(obj) (CFAutorelease(obj))
#define oc_retaincount(obj) (CFGetRetainCount(obj))

//------------------------------------------------------------------------------

oc_framework(Foundation)
oc_import(
    Foundation,
    function(bool,        class_addIvar,(Class, const char* name, size_t size, uint8_t alignment, const char* types)),
    function(bool,        class_addMethod,(Class, SEL, IMP, const char* types)),
    function(Method*,     class_copyMethodList,(Class, unsigned int *outCount)),
    function(Property*,   class_copyPropertyList,(Class, unsigned int *outCount)),
    function(Ivar*,       class_copyIvarList,(Class, unsigned int *outCount)),
    function(Method,      class_getClassMethod,(Class, SEL)),
    function(Method,      class_getInstanceMethod,(Class, SEL)),
    function(size_t,      class_getInstanceSize,(Class)),
    function(Ivar,        class_getInstanceVariable,(Class, const char* name)),
    function(IMP,         class_getMethodImplementation,(Class, SEL)),
    function(const char*, class_getName,(Class)),
    function(Property,    class_getProperty,(Class, const char *name)),
    function(Class,       class_getSuperclass,(Class)),
    function(const char*, ivar_getName,(Ivar v)),
    function(ptrdiff_t,   ivar_getOffset,(Ivar)),
    function(SEL,         method_getName,(Method m)),
    function(const char*, method_getTypeEncoding,(Method)),
    function(IMP,         method_setImplementation,(Method, IMP)),
    function(Class,       objc_allocateClassPair,(Class, const char* name, size_t extraBytes)),
    function(void*,       objc_autorelease,(void*)),
    function(void,        objc_autoreleasePoolPop,(void*)),
    function(void*,       objc_autoreleasePoolPush,(void)),
    function(void*,       objc_constructInstance,(Class, void* bytes)),
    function(void,        objc_destructInstance,(void*)),
    function(Class,       objc_getClass,(const char* name)),
    function(void*,       objc_getProtocol,(const char* name)),
    function(void*,       objc_msgSend,(id, SEL, ...)),
    function(void,        objc_msgSend_stret,(id, SEL, ...)),
    function(void*,       objc_msgSendSuper2,(objc_super2*, SEL, ...)),
    function(void,        objc_msgSendSuper2_stret,(objc_super2*, SEL, ...)),
    function(void,        objc_registerClassPair,(Class)),
    function(void,        objc_release,(void*)),
    function(void*,       objc_retain,(void*)),
    function(Class,       object_getClass,(void*)),
    function(const char*, sel_getName,(SEL)),
    function(SEL,         sel_getUid,(const char*)),
)

#if defined(__x86_64__) || defined(__i386__)

    oc_import(
        Foundation,
        function(long double,objc_msgSend_fpret,(id, SEL, ...)),
    )

#elif defined(__arm__)

    #define objc_msgSend_fpret objc_msgSend

#endif

//------------------------------------------------------------------------------

#include "detail/message.h"
#define oc_cls(CLASS, /*PARAMS*/...)\
        _oc_msg_send(CLASS##_class, CLASS, __VA_ARGS__)

#define oc_obj(SELF, CLASS, /*PARAMS*/...)\
        _oc_msg_send(SELF, CLASS, __VA_ARGS__)

#define oc_super(CLASS, /*PARAMS*/...)\
        _oc_msg_send_super(CLASS, __VA_ARGS__)

//------------------------------------------------------------------------------

#define oc_class(NAME) typedef struct NAME NAME;

oc_class(NSObject)

//------------------------------------------------------------------------------

#include "detail/interface.h"
#define oc_interface(CLASS, /*SYMBOLS*/...)\
        _oc_interface(CLASS, __VA_ARGS__)

oc_interface(
    NSObject,
)

//------------------------------------------------------------------------------

#include "detail/implementation.h"
#define oc_implementation(CLASS, SUPERCLASS, /*SYMBOLS*/...)\
        _oc_implementation(CLASS, SUPERCLASS, __VA_ARGS__)
/*
    Example:
        oc_implementation(
            AppWindow, NSWindow,
            var(void*,context),
            obj(void,dealloc),
            obj(bool,windowShouldClose,NSNotification*,(
                return true;
            )),
            obj(void,windowWillClose,NSNotification*,(
                puts(__func__);
            )),
        )
*/

//------------------------------------------------------------------------------

#include "detail/var.h"
#define oc_var(SELF, CLASS, NAME)\
        _oc_var(SELF, CLASS, NAME)

//------------------------------------------------------------------------------

#include "detail/method.h"
#define oc_method(RESULT, CLASS, /*PARAMS*/...)\
        _oc_method(RESULT, CLASS, __VA_ARGS__)

//------------------------------------------------------------------------------

#include "detail/swizzle.h"
#define oc_cls_swizzle(RESULT, CLASS, /*PARAMS*/...)\
        _oc_msg_swizzle(RESULT, CLASS, Class, ClassMethod, __VA_ARGS__)

#define oc_obj_swizzle(RESULT, CLASS, /*PARAMS*/...)\
        _oc_msg_swizzle(RESULT, CLASS, CLASS*, InstanceMethod, __VA_ARGS__)


//------------------------------------------------------------------------------

#endif // OC_H_6BD98208_07AE_43B7_98CF_8B81AD3BEABF
