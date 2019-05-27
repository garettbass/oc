# OC - Easily Declare/Invoke Objective-C APIs from C11 or C++11

## Usage

```c
// Call class and instance methods:
NSWindow* const nswindow = oc_cls(NSWindow,new);
oc_obj(nswindow,NSWindow,setRestorable,false);
oc_obj(nswindow,NSWindow,setReleasedWhenClosed,false);
oc_obj(nswindow,NSWindow,setStyleMask,windowStyle);
oc_obj(nswindow,NSWindow,setFrame,windowRect,display,true);
oc_obj(nswindow,NSWindow,setIsVisible,true);
oc_obj(nswindow,NSWindow,center);
```

```c
// Swizzle methods:
oc_obj_swizzle(void,NSWindow,dealloc) {
    printf("NSWindow.%s\n",(const char*)cmd);
    imp(self, cmd);
}
```

```c
// Declare and implement classes:
oc_interface(
    AppDelegate,
)

oc_implementation(
    AppDelegate, NSObject,
    obj(void,
        applicationDidFinishLaunching,NSNotification*),
    obj(NSApplicationTerminateReply,
        applicationShouldTerminate,NSApplication*),
    obj(void,
        applicationWillTerminate,NSNotification*),
)

oc_method(
    void,
    AppDelegate,
    applicationDidFinishLaunching,NSNotification*
) {
    puts(__func__);
}

oc_method(
    NSApplicationTerminateReply,
    AppDelegate,
    applicationShouldTerminate,NSApplication*
) {
    puts(__func__);
    appQuit();
    return NSApplicationTerminateCancel;
}

oc_method(
    void,
    AppDelegate,
    applicationWillTerminate,NSNotification*
) {
    puts(__func__);
    appQuit();
}
```