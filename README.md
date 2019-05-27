# OC - Easily Declare/Invoke Objective-C APIs from C11 or C++11

## Usage

```c
    // see appkit.h for NSWindow declaration
    NSWindow* const nswindow = oc_cls(NSWindow,new);
    oc_obj(nswindow,NSWindow,setRestorable,false);
    oc_obj(nswindow,NSWindow,setReleasedWhenClosed,false);
    oc_obj(nswindow,NSWindow,setStyleMask,windowStyle);
    oc_obj(nswindow,NSWindow,setFrame,windowRect,display,true);
    oc_obj(nswindow,NSWindow,setIsVisible,true);
    oc_obj(nswindow,NSWindow,center);
```