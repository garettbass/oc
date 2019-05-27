#pragma once
#include "foundation.h"

//------------------------------------------------------------------------------

oc_framework(AppKit)

oc_class(NSApplication)
oc_class(NSCursor)
oc_class(NSDate)
oc_class(NSEvent)
oc_class(NSMenu)
oc_class(NSMenuItem)
oc_class(NSNotificationCenter)
oc_class(NSPersistentUIManager)
oc_class(NSScreen)
oc_class(NSView)
oc_class(NSWindow)

//------------------------------------------------------------------------------

typedef enum NSApplicationTerminateReply {
    NSApplicationTerminateCancel = 0,
    NSApplicationTerminateNow    = 1,
    NSApplicationTerminateLater  = 2,
} NSApplicationTerminateReply;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum NSBackingStoreType {
    NSBackingStoreBuffered = 2,
} NSBackingStoreType;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum NSEventMask {
    NSEventMaskAny = (int)~0u,
} NSEventMask;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum NSEventType {
    NSEventTypeLeftMouseDown      = 1,
    NSEventTypeLeftMouseUp        = 2,
    NSEventTypeRightMouseDown     = 3,
    NSEventTypeRightMouseUp       = 4,
    NSEventTypeMouseMoved         = 5,
    NSEventTypeLeftMouseDragged   = 6,
    NSEventTypeRightMouseDragged  = 7,
    NSEventTypeMouseEntered       = 8,
    NSEventTypeMouseExited        = 9,
    NSEventTypeKeyDown            = 10,
    NSEventTypeKeyUp              = 11,
    NSEventTypeFlagsChanged       = 12,
    NSEventTypeAppKitDefined      = 13,
    NSEventTypeSystemDefined      = 14,
    NSEventTypeApplicationDefined = 15,
    NSEventTypePeriodic           = 16,
    NSEventTypeCursorUpdate       = 17,
    NSEventTypeScrollWheel        = 22,
    NSEventTypeTabletPoint        = 23,
    NSEventTypeTabletProximity    = 24,
    NSEventTypeOtherMouseDown     = 25,
    NSEventTypeOtherMouseUp       = 26,
    NSEventTypeOtherMouseDragged  = 27,
    NSEventTypeGesture            = 29,
    NSEventTypeMagnify            = 30,
    NSEventTypeSwipe              = 31,
    NSEventTypeRotate             = 18,
    NSEventTypeBeginGesture       = 19,
    NSEventTypeEndGesture         = 20,
    NSEventTypeSmartMagnify       = 32,
    NSEventTypeQuickLook          = 33,
    NSEventTypePressure           = 34,
    NSEventTypeDirectTouch        = 37,
} NSEventType;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum NSEventSubtype {
    /* event subtypes for NSEventTypeAppKitDefined events */
    NSEventSubtypeWindowExposed          = 0,
    NSEventSubtypeApplicationActivated   = 1,
    NSEventSubtypeApplicationDeactivated = 2,
    NSEventSubtypeWindowMoved            = 4,
    NSEventSubtypeScreenChanged          = 8,

    /* event subtypes for NSEventTypeSystemDefined events */
    NSEventSubtypePowerOff  = 1,

    /* event subtypes for mouse events */
    NSEventSubtypeMouseEvent      = 0,
    NSEventSubtypeTabletPoint     = 1,
    NSEventSubtypeTabletProximity = 2,
    NSEventSubtypeTouch           = 3,
} NSEventSubtype;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum NSEventModifierFlags {
    NSEventModifierFlagCapsLock   = 1 << 16,
    NSEventModifierFlagShift      = 1 << 17,
    NSEventModifierFlagControl    = 1 << 18,
    NSEventModifierFlagOption     = 1 << 19,
    NSEventModifierFlagCommand    = 1 << 20,
    NSEventModifierFlagNumericPad = 1 << 21,
    NSEventModifierFlagHelp       = 1 << 22,
    NSEventModifierFlagFunction   = 1 << 23,
} NSEventModifierFlags;

// Used to retrieve only the device-independent modifier flags,
// allowing applications to mask off the device-dependent modifier flags,
// including event coalescing information.
#define NSEventModifierFlagDeviceIndependentFlagsMask (0xffff0000UL)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum NSWindowStyleMask {
    NSWindowStyleMaskBorderless             = 0,
    NSWindowStyleMaskTitled                 = 1 << 0,
    NSWindowStyleMaskClosable               = 1 << 1,
    NSWindowStyleMaskMiniaturizable         = 1 << 2,
    NSWindowStyleMaskResizable              = 1 << 3,
    NSWindowStyleMaskUtilityWindow          = 1 << 4,
    NSWindowStyleMaskDocModalWindow         = 1 << 6,
    NSWindowStyleMaskNonactivatingPanel     = 1 << 7,
    NSWindowStyleMaskUnifiedTitleAndToolbar = 1 << 12,
    NSWindowStyleMaskFullScreen             = 1 << 14,
    NSWindowStyleMaskFullSizeContentView    = 1 << 15,
    NSWindowStyleMaskHUDWindow              = 1 << 13,
} NSWindowStyleMask;

//------------------------------------------------------------------------------

oc_interface(
    NSApplication,
    cls(NSApplication*, sharedApplication),
    obj(void,           activateIgnoringOtherApps,bool),
    obj(id,             delegate),
    obj(void,           finishLaunching),
    obj(bool,           isActive),
    obj(NSWindow*,      keyWindow),
    obj(NSMenu*,        mainMenu),
    obj(NSEvent*,       nextEventMatchingMask,NSEventMask,
                        untilDate,NSDate*,
                        inMode,NSString*,
                        dequeue,bool),
    obj(void,           sendEvent,NSEvent*),
    obj(void,           setActivationPolicy,size_t),
    obj(void,           setDelegate,id),
    obj(void,           setMainMenu,NSMenu*),
    obj(void,           terminate,id),
    obj(void,           updateWindows),
)

#define NSApp (oc_cls(NSApplication, sharedApplication))

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    NSCursor,
    cls(NSCursor*, currentCursor),
    cls(NSCursor*, currentSystemCursor),
    cls(NSCursor*, arrowCursor),
    cls(NSCursor*, IBeamCursor),
    cls(NSCursor*, crosshairCursor),
    cls(NSCursor*, closedHandCursor),
    cls(NSCursor*, openHandCursor),
    cls(NSCursor*, pointingHandCursor),
    cls(NSCursor*, resizeLeftCursor),
    cls(NSCursor*, resizeRightCursor),
    cls(NSCursor*, resizeLeftRightCursor),
    cls(NSCursor*, resizeUpCursor),
    cls(NSCursor*, resizeDownCursor),
    cls(NSCursor*, resizeUpDownCursor),
    cls(NSCursor*, disappearingItemCursor),
    cls(NSCursor*, IBeamCursorForVerticalLayout),
    cls(NSCursor*, operationNotAllowedCursor),
    cls(NSCursor*, dragLinkCursor),
    cls(NSCursor*, dragCopyCursor),
    cls(NSCursor*, contextualMenuCursor),
    cls(NSCursor*, hide),
    cls(NSCursor*, unhide),
    obj(NSCursor*, initWithCGImage,id,size,NSSize),
    obj(void,      push),
    obj(void,      pop),
    obj(void,      set),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    NSDate,
    cls(NSDate*, date),
    cls(NSDate*, dateWithTimeIntervalSinceNow,NSTimeInterval),
    cls(NSDate*, dateWithTimeInterval,NSTimeInterval,sinceDate,NSDate*),
    cls(NSDate*, distantPast),
    cls(NSDate*, distantFuture),
    obj(NSDate*, initWithTimeInterval,NSTimeInterval,sinceDate,NSDate*),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    NSEvent,
    cls(NSTimeInterval,         doubleClickInterval),
    cls(NSTimeInterval,         keyRepeatDelay),
    cls(NSTimeInterval,         keyRepeatInterval),
    cls(NSUInteger,             pressedMouseButtons),
    cls(NSPoint,                mouseLocation),
    obj(NSInteger,              buttonNumber),
    obj(NSInteger,              clickCount),
    obj(NSPoint,                locationInWindow),
    obj(CGFloat,                deltaX),
    obj(CGFloat,                deltaY),
    obj(CGFloat,                deltaZ),
    obj(NSInteger,              absoluteX),
    obj(NSInteger,              absoluteY),
    obj(NSInteger,              absoluteZ),
    obj(CGFloat,                scrollingDeltaX),
    obj(CGFloat,                scrollingDeltaY),
    obj(NSEventModifierFlags,   modifierFlags),
    obj(NSEventSubtype,         subtype),
    obj(NSTimeInterval,         timestamp),
    obj(NSEventType,            type),
    obj(NSWindow*,              window),
    obj(NSString*,              characters),
    obj(NSString*,              charactersIgnoringModifiers),
    obj(bool,                   isARepeat),
    obj(unsigned short,         keyCode),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    NSMenu,
    obj(NSMenu*, initWithTitle,NSString*),
    obj(void,    addItem,NSMenuItem*),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    NSMenuItem,
    obj(NSMenuItem*,    initWithTitle,NSString*,
                        action,SEL,
                        keyEquivalent,NSString*),
    obj(void,           setKeyEquivalentModifierMask,NSEventModifierFlags),
    obj(void,           setSubmenu,NSMenu*),
    obj(void,           setTarget,id),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    NSNotificationCenter,
    cls(NSNotificationCenter*,defaultCenter),
    obj(void,postNotificationName,NSString*,object,id),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    NSPersistentUIManager,
    cls(NSPersistentUIManager*, sharedManager),
    obj(bool,                   shouldRestoreStateOnLaunch),
    obj(bool,                   promptToIgnorePersistentState),
    obj(void,                   ignoreAnyPreexistingPersistentState),
    obj(void,                   disableRestorableStateWriting),
    obj(void,                   invalidateStateDirectoryAtLaunch),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    NSScreen,
    cls(NSScreen*,   mainScreen),
    cls(NSArray*,    screens),
    obj(NSRect,      frame),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    NSWindow,
    obj(NSWindow*,          initWithContentRect,NSRect,
                            styleMask,NSWindowStyleMask,
                            backing,NSBackingStoreType,
                            defer,bool,
                            screen,NSScreen*),
    obj(void,               center),
    obj(void,               close),
    obj(NSRect,             contentRectForFrameRect,NSRect),
    obj(NSView*,            contentView),
    obj(void,               deminiaturize,id),
    obj(void,               disableSnapshotRestoration),
    obj(NSRect,             frame),
    obj(NSRect,             frameRectForContentRect,NSRect),
    obj(bool,               isDocumentEdited),
    obj(bool,               isKeyWindow),
    obj(bool,               isMainWindow),
    obj(bool,               isMiniaturized),
    obj(bool,               isRestorable),
    obj(bool,               isVisible),
    obj(bool,               isZoomed),
    obj(void,               keyDown,NSEvent*),
    obj(void,               makeKeyAndOrderFront,id),
    obj(void,               makeMainWindow),
    obj(void,               orderFront,id),
    obj(void,               miniaturize,id),
    obj(void,               setAcceptsMouseMovedEvents,bool),
    obj(void,               setCollectionBehavior,size_t),
    obj(void,               setContentView,NSView*),
    obj(void,               setDelegate,id),
    obj(void,               setDocumentEdited,bool),
    obj(void,               setFrame,NSRect, display,bool),
    obj(void,               setRestorable,bool),
    obj(void,               setRestorationClass,Class),
    obj(void,               setIsVisible,bool),
    obj(void,               setReleasedWhenClosed,bool),
    obj(void,               setStyleMask,NSWindowStyleMask),
    obj(void,               setTitle,NSString*),
    obj(void,               setTitlebarAppearsTransparent,bool),
    obj(NSWindowStyleMask,  styleMask),
    obj(bool,               titlebarAppearsTransparent),
    obj(void,               zoom,id),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    NSView,
    obj(NSView*,    superview),
    obj(NSArray*,   subviews),
    obj(NSRect,     bounds),
    obj(NSRect,     frame),
    obj(NSWindow*,  window),
    obj(void,       removeFromSuperview),
)

//------------------------------------------------------------------------------
