#pragma once
#include "foundation.h"

//------------------------------------------------------------------------------

oc_framework(Carbon)

//------------------------------------------------------------------------------

typedef enum HICoordinateSpace {
    // The coordinate space defined by the position and sizes of the
    // screen GDevices. More correctly, this is a 72 DPI coordinate space
    // covering the screens. When the scale factor is not 1.0, this is
    // the compatibility notion of parameter coordinates. When the scale
    // factor is 1.0, this and kHICoordSpaceScreenPixel are the same.
    kHICoordSpace72DPIParameter = 1,

    // The coordinate space defined by physical screen pixels. When the
    // scale factor is 1.0, this and kHICoordSpace72DPIParameter are the
    // same.
    kHICoordSpaceScreenPixel = 2,

    // The coordinate space of a specified WindowRef, with { 0, 0 } at
    // the top left of the window's structure. When this is passed to a
    // conversion routine as a source or destination coordinate space,
    // you must also pass a WindowRef as a source or destination object.
    kHICoordSpaceWindow      = 3,

    // The coordinate space of a given HIViewRef, with { 0, 0 } at the
    // top left of the view unless changed by HIViewSetBoundsOrigin. When
    // this is passed to a conversion routine as a source or destination
    // coordinate space, you must also pass an HIViewRef as a source or
    // destination object.
    kHICoordSpaceView        = 4
} HICoordinateSpace;

enum {
    kVK_A               = 0x00,
    kVK_S               = 0x01,
    kVK_D               = 0x02,
    kVK_F               = 0x03,
    kVK_H               = 0x04,
    kVK_G               = 0x05,
    kVK_Z               = 0x06,
    kVK_X               = 0x07,
    kVK_C               = 0x08,
    kVK_V               = 0x09,
    kVK_ISO_Section     = 0x0A,
    kVK_B               = 0x0B,
    kVK_Q               = 0x0C,
    kVK_W               = 0x0D,
    kVK_E               = 0x0E,
    kVK_R               = 0x0F,
    kVK_Y               = 0x10,
    kVK_T               = 0x11,
    kVK_1               = 0x12,
    kVK_2               = 0x13,
    kVK_3               = 0x14,
    kVK_4               = 0x15,
    kVK_6               = 0x16,
    kVK_5               = 0x17,
    kVK_Equal           = 0x18,
    kVK_9               = 0x19,
    kVK_7               = 0x1A,
    kVK_Minus           = 0x1B,
    kVK_8               = 0x1C,
    kVK_0               = 0x1D,
    kVK_RightBracket    = 0x1E,
    kVK_O               = 0x1F,
    kVK_U               = 0x20,
    kVK_LeftBracket     = 0x21,
    kVK_I               = 0x22,
    kVK_P               = 0x23,
    kVK_Return          = 0x24,
    kVK_L               = 0x25,
    kVK_J               = 0x26,
    kVK_Quote           = 0x27,
    kVK_K               = 0x28,
    kVK_Semicolon       = 0x29,
    kVK_Backslash       = 0x2A,
    kVK_Comma           = 0x2B,
    kVK_Slash           = 0x2C,
    kVK_N               = 0x2D,
    kVK_M               = 0x2E,
    kVK_Period          = 0x2F,
    kVK_Tab             = 0x30,
    kVK_Space           = 0x31,
    kVK_Grave           = 0x32,
    kVK_Delete          = 0x33,
    kVK_0x34            = 0x34,
    kVK_Escape          = 0x35,
    kVK_0x36            = 0x36,
    kVK_Command         = 0x37,
    kVK_Shift           = 0x38,
    kVK_CapsLock        = 0x39,
    kVK_Option          = 0x3A,
    kVK_Control         = 0x3B,
    kVK_RightShift      = 0x3C,
    kVK_RightOption     = 0x3D,
    kVK_RightControl    = 0x3E,
    kVK_Function        = 0x3F,
    kVK_F17             = 0x40,
    kVK_KeypadDecimal   = 0x41,
    kVK_0x42            = 0x42,
    kVK_KeypadMultiply  = 0x43,
    kVK_0x44            = 0x44,
    kVK_KeypadPlus      = 0x45,
    kVK_0x46            = 0x46,
    kVK_KeypadClear     = 0x47,
    kVK_VolumeUp        = 0x48,
    kVK_VolumeDown      = 0x49,
    kVK_Mute            = 0x4A,
    kVK_KeypadDivide    = 0x4B,
    kVK_KeypadEnter     = 0x4C,
    kVK_KeypadMinus     = 0x4E,
    kVK_F18             = 0x4F,
    kVK_F19             = 0x50,
    kVK_KeypadEquals    = 0x51,
    kVK_Keypad0         = 0x52,
    kVK_Keypad1         = 0x53,
    kVK_Keypad2         = 0x54,
    kVK_Keypad3         = 0x55,
    kVK_Keypad4         = 0x56,
    kVK_Keypad5         = 0x57,
    kVK_Keypad6         = 0x58,
    kVK_Keypad7         = 0x59,
    kVK_F20             = 0x5A,
    kVK_Keypad8         = 0x5B,
    kVK_Keypad9         = 0x5C,
    kVK_JIS_Yen         = 0x5D,
    kVK_JIS_Underscore  = 0x5E,
    kVK_JIS_KeypadComma = 0x5F,
    kVK_F5              = 0x60,
    kVK_F6              = 0x61,
    kVK_F7              = 0x62,
    kVK_F3              = 0x63,
    kVK_F8              = 0x64,
    kVK_F9              = 0x65,
    kVK_JIS_Eisu        = 0x66,
    kVK_F11             = 0x67,
    kVK_JIS_Kana        = 0x68,
    kVK_F13             = 0x69,
    kVK_F16             = 0x6A,
    kVK_F14             = 0x6B,
    kVK_0x6C            = 0x6C,
    kVK_F10             = 0x6D,
    kVK_0x6E            = 0x6E,
    kVK_F12             = 0x6F,
    kVK_0x70            = 0x70,
    kVK_F15             = 0x71,
    kVK_Help            = 0x72,
    kVK_Home            = 0x73,
    kVK_PageUp          = 0x74,
    kVK_ForwardDelete   = 0x75,
    kVK_F4              = 0x76,
    kVK_End             = 0x77,
    kVK_F2              = 0x78,
    kVK_PageDown        = 0x79,
    kVK_F1              = 0x7A,
    kVK_LeftArrow       = 0x7B,
    kVK_RightArrow      = 0x7C,
    kVK_DownArrow       = 0x7D,
    kVK_UpArrow         = 0x7E,
    kVK_Invalid         = 0x80,
};

typedef unsigned HIKeyMap[4];

//------------------------------------------------------------------------------

oc_import(
    Carbon,
    function(CGPoint*, HIGetMousePosition,(
        HICoordinateSpace   inSpace,
        void *              inObject,
        CGPoint *           outPoint)),
    function(unsigned, GetCurrentButtonState,(void)),
    function(unsigned, GetCurrentKeyModifiers,(void)),
    function(void,     GetKeys,(HIKeyMap)),
)

//------------------------------------------------------------------------------
