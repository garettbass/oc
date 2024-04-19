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

typedef struct objc_class      objc_class;
typedef struct objc_ivar       objc_ivar;
typedef struct objc_method     objc_method;
typedef struct objc_selector   objc_selector;
typedef struct objc_property   objc_property, *Property;
typedef struct objc_super2     objc_super2;

typedef id (*objc_imp)(id, objc_selector*, ...);

/*------------------------------------------------------------------------------
oc_framework(FRAMEWORK) - load an Objective-C framework
oc_import(FRAMEWORK, SYMBOLS...) - import symbols from a framework

Usage:

    oc_framework(Foundation)
    oc_import(
        Foundation,
        function(void,objc_release,(void*)),
        function(void,objc_retain,(void*)),
    )

*/
#define oc_framework(FRAMEWORK) _oc_framework(FRAMEWORK)
#include "detail/framework.h"

#define oc_import(FRAMEWORK, /*SYMBOLS*/...) _oc_import(FRAMEWORK, __VA_ARGS__)
#include "detail/import.h"

//------------------------------------------------------------------------------

oc_framework(CoreFoundation)
oc_import(
    CoreFoundation,
    function(signed long, CFGetRetainCount,(const void*)),
)

//------------------------------------------------------------------------------

oc_framework(Foundation)
oc_import(
    Foundation,
    function(bool,           class_addIvar,(objc_class*, const char* name, size_t size, uint8_t alignment, const char* types)),
    function(bool,           class_addMethod,(objc_class*, objc_selector*, objc_imp, const char* types)),
    function(objc_method**,  class_copyMethodList,(objc_class*, unsigned int *outCount)),
    function(objc_ivar**,    class_copyIvarList,(objc_class*, unsigned int *outCount)),
    function(objc_method*,   class_getClassMethod,(objc_class*, objc_selector*)),
    function(objc_method*,   class_getInstanceMethod,(objc_class*, objc_selector*)),
    function(size_t,         class_getInstanceSize,(objc_class*)),
    function(objc_ivar*,     class_getInstanceVariable,(objc_class*, const char* name)),
    function(objc_imp,       class_getMethodImplementation,(objc_class*, objc_selector*)),
    function(const char*,    class_getName,(objc_class*)),
    function(objc_class*,    class_getSuperclass,(objc_class*)),
    function(const char*,    ivar_getName,(objc_ivar*)),
    function(ptrdiff_t,      ivar_getOffset,(objc_ivar*)),
    function(objc_selector*, method_getName,(objc_method* m)),
    function(const char*,    method_getTypeEncoding,(objc_method*)),
    function(objc_imp,       method_setImplementation,(objc_method*, objc_imp)),
    function(objc_class*,    objc_allocateClassPair,(objc_class*, const char* name, size_t extraBytes)),
    function(id,             objc_autorelease,(void*)),
    function(void,           objc_autoreleasePoolPop,(void*)),
    function(void*,          objc_autoreleasePoolPush,(void)),
    function(void*,          objc_constructInstance,(objc_class*, void* bytes)),
    function(void,           objc_destructInstance,(void*)),
    function(objc_class*,    objc_getClass,(const char* name)),
    function(void*,          objc_getProtocol,(const char* name)),
    function(void*,          objc_msgSend,(id, objc_selector*, ...)),
    function(void*,          objc_msgSendSuper2,(objc_super2*, objc_selector*, ...)),
    function(void,           objc_registerClassPair,(objc_class*)),
    function(void,           objc_release,(void*)),
    function(id,             objc_retain,(void*)),
    function(objc_class*,    object_getClass,(void*)),
    function(const char*,    sel_getName,(objc_selector*)),
    function(objc_selector*, sel_getUid,(const char*)),
)

#if defined(__x86_64__) || defined(__i386__)

    oc_import(
        Foundation,
        function(long double,objc_msgSend_fpret,(id, objc_selector*, ...)),
        function(void,       objc_msgSend_stret,(id, objc_selector*, ...)),
        function(void,       objc_msgSendSuper2_stret,(objc_super2*, objc_selector*, ...)),
    )

#elif defined(__arm__)

    oc_import(
        Foundation,
        function(void,       objc_msgSend_stret,(id, objc_selector*, ...)),
        function(void,       objc_msgSendSuper2_stret,(objc_super2*, objc_selector*, ...)),
    )

    #define objc_msgSend_fpret objc_msgSend

#elif defined(__aarch64__)

    #define objc_msgSend_fpret       objc_msgSend
    #define objc_msgSend_stret       objc_msgSend
    #define objc_msgSendSuper2_stret objc_msgSendSuper2

#endif

#define oc_retain(obj)      (objc_retain(obj))
#define oc_release(obj)     (objc_release(obj))
#define oc_autorelease(obj) (objc_autorelease(obj))

/*------------------------------------------------------------------------------
oc_autoreleasepool - scoped autorelease pool
*/

#define oc_autoreleasepool\
    for(__attribute__((cleanup(oc_autoreleasepool_cleanup)))\
        void* oc_autoreleasepool = objc_autoreleasePoolPush();\
        oc_autoreleasepool;\
        oc_autoreleasepool_cleanup(&oc_autoreleasepool))

static inline void oc_autoreleasepool_cleanup(void** ppool) {
    if (*ppool) { objc_autoreleasePoolPop(*ppool); *ppool = NULL; }
}

/*------------------------------------------------------------------------------
oc_class(NAME) - forward declare an Objective-C class
*/
#define oc_class(NAME) typedef struct NAME NAME

oc_class(NSObject);

/*------------------------------------------------------------------------------
oc_interface(CLASS, SYMBOLS...) - declare an Objective-C class interface

Usage:

    oc_interface(
        NSDate,
        cls(NSDate*, date),
        cls(NSDate*, dateWithTimeIntervalSinceNow,NSTimeInterval),
        cls(NSDate*, dateWithTimeInterval,NSTimeInterval,sinceDate,NSDate*),
        cls(NSDate*, distantPast),
        cls(NSDate*, distantFuture),
        obj(NSDate*, initWithTimeInterval,NSTimeInterval,sinceDate,NSDate*),
    )

*/
#include "detail/message.h"
#include "detail/interface.h"
#define oc_interface(CLASS, /*SYMBOLS*/...)\
        _oc_interface(CLASS, __VA_ARGS__)

oc_interface(
    NSObject,
)

/*------------------------------------------------------------------------------
oc_implementation(CLASS, SUPERCLASS, SYMBOLS...) - define an Objective-C class
oc_method(RESULT, CLASS, PARAMS...) - define a class method implementation

Usage:

    oc_interface(
        AppDelegate,
    )

    oc_implementation(
        AppDelegate, NSObject,
        obj(NSApplicationTerminateReply,
            applicationShouldTerminate,NSApplication*),
    )

    oc_method(
        NSApplicationTerminateReply,
        AppDelegate,
        applicationShouldTerminate,NSApplication*
    ) {
        puts(__func__);
        app_quit();
        return NSApplicationTerminateCancel;
    }

*/
#include "detail/implementation.h"
#define oc_implementation(CLASS, SUPERCLASS, /*SYMBOLS*/...)\
        _oc_implementation(CLASS, SUPERCLASS, __VA_ARGS__)

#include "detail/method.h"
#define oc_method(RESULT, CLASS, /*PARAMS*/...)\
        _oc_method(RESULT, CLASS, __VA_ARGS__)

/*------------------------------------------------------------------------------
oc_cls(CLASS, PARAMS...) - call an Objective-C class method

Usage:

    NSWindow* const nsWindow = oc_cls(NSWindow,new);

*/
#define oc_cls(CLASS, /*PARAMS*/...)\
        _oc_msg_send(CLASS##_class, CLASS, __VA_ARGS__)

/*------------------------------------------------------------------------------
oc_obj(CLASS, PARAMS...) - call an Objective-C object method

Usage:

    oc_obj(nsWindow,NSWindow,setReleasedWhenClosed,false);

*/
#define oc_obj(SELF, CLASS, /*PARAMS*/...)\
        _oc_msg_send(SELF, CLASS, __VA_ARGS__)

/*------------------------------------------------------------------------------
oc_super(CLASS, PARAMS...) - call an Objective-C super method

Usage:

    oc_method(app_window*,app_window,alloc) {
        puts((const char*)cmd);
        return oc_super(app_window,alloc);
    }

*/
#define oc_super(CLASS, /*PARAMS*/...)\
        _oc_msg_send_super(CLASS, __VA_ARGS__)

/*------------------------------------------------------------------------------
oc_var(SELF, CLASS, NAME) - get/set an Objective-C object member variable

Usage:

    oc_implementation(
        AppMenuItem, NSMenuItem,
        var(AppMenuCallback,    callback),
        cls(NSMenuItem*,        menuItemWithTitle,NSString*,
                                callback,AppMenuCallback,
                                keyEquivalent,NSString*),
        obj(void,               invokeCallback),
        obj(bool,               validateMenuItem,NSMenuItem*),
    )

    //...

    oc_var(item,AppMenuItem,callback) = callback;

*/
#include "detail/var.h"
#define oc_var(SELF, CLASS, NAME)\
        _oc_var(SELF, CLASS, NAME)


/*------------------------------------------------------------------------------
oc_cls_swizzle(RESULT, CLASS, PARAMS...) - replace class method implementation
oc_obj_swizzle(RESULT, CLASS, PARAMS...) - replace object method implementation

Usage:

    oc_cls_swizzle(id, NSObject, alloc) {
        printf("%s.%s\n", class_getName(self), (const char*)cmd);
        return imp(self, cmd);
    }

    oc_obj_swizzle(void, NSObject, dealloc) {
        printf("%s.%s\n", class_getName(object_getClass(self)), (const char*)cmd);
        imp(self, cmd);
    }

*/
#include "detail/swizzle.h"
#define oc_cls_swizzle(RESULT, CLASS, /*PARAMS*/...)\
        _oc_msg_swizzle(RESULT, CLASS, objc_class*, ClassMethod, __VA_ARGS__)

#define oc_obj_swizzle(RESULT, CLASS, /*PARAMS*/...)\
        _oc_msg_swizzle(RESULT, CLASS, CLASS*, InstanceMethod, __VA_ARGS__)

//------------------------------------------------------------------------------

#endif // OC_H_6BD98208_07AE_43B7_98CF_8B81AD3BEABF
