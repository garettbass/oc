#pragma once
#include "foundation.h"

//------------------------------------------------------------------------------

oc_framework(CoreGraphics)

//------------------------------------------------------------------------------

typedef enum CGError {
    CGErrorSuccess           = 0,
    CGErrorFailure           = 1000,
    CGErrorIllegalArgument   = 1001,
    CGErrorInvalidConnection = 1002,
    CGErrorInvalidContext    = 1003,
    CGErrorCannotComplete    = 1004,
    CGErrorNotImplemented    = 1006,
    CGErrorRangeCheck        = 1007,
    CGErrorTypeCheck         = 1008,
    CGErrorInvalidOperation  = 1010,
    CGErrorNoneAvailable     = 1011,
} CGError;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum CGColorRenderingIntent {
    CGRenderingIntentDefault,
    CGRenderingIntentAbsoluteColorimetric,
    CGRenderingIntentRelativeColorimetric,
    CGRenderingIntentPerceptual,
    CGRenderingIntentSaturation
} CGColorRenderingIntent;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum CGImageByteOrderInfo {
    CGImageByteOrderMask     = 0x7000,
    CGImageByteOrderDefault  = 0 << 12,
    CGImageByteOrder16Little = 1 << 12,
    CGImageByteOrder32Little = 2 << 12,
    CGImageByteOrder16Big    = 3 << 12,
    CGImageByteOrder32Big    = 4 << 12,
} CGImageByteOrderInfo;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum CGBitmapInfo {
    CGBitmapAlphaInfoMask = 0x1F,

    CGBitmapFloatInfoMask = 0xF00,
    CGBitmapFloatComponents = (1 << 8),

    CGBitmapByteOrderMask     = CGImageByteOrderMask,
    CGBitmapByteOrderDefault  = CGImageByteOrderDefault,
    CGBitmapByteOrder16Little = CGImageByteOrder16Little,
    CGBitmapByteOrder32Little = CGImageByteOrder32Little,
    CGBitmapByteOrder16Big    = CGImageByteOrder16Big,
    CGBitmapByteOrder32Big    = CGImageByteOrder32Big
} CGBitmapInfo;

//------------------------------------------------------------------------------

typedef struct CGDisplayMode *CGDisplayModeRef;

typedef struct CGImage *CGImageRef;

typedef struct CGColorSpace *CGColorSpaceRef;

typedef struct CGDataProvider *CGDataProviderRef;

typedef void (*CGDataProviderReleaseDataCallback)(
    void* info,
    const void* data,
    size_t size);

//------------------------------------------------------------------------------

oc_import(
    CoreGraphics,
    function(
        CGError,
        CGAssociateMouseAndMouseCursorPosition,(int connected)),
    function(
        unsigned,
        CGMainDisplayID,(void)),
    function(
        CGDisplayModeRef,
        CGDisplayCopyDisplayMode,(unsigned display)),
    function(
        double,
        CGDisplayModeGetRefreshRate,(CGDisplayModeRef mode)),
    function(
        void,
        CGDisplayModeRelease,(CGDisplayModeRef mode)),
    function(
        CGImageRef,
        CGImageCreate,(
            size_t width,
            size_t height,
            size_t bitsPerComponent,
            size_t bitsPerPixel,
            size_t bytesPerRow,
            CGColorSpaceRef space,
            CGBitmapInfo bitmapInfo,
            CGDataProviderRef provider,
            const CGFloat *decode,
            bool shouldInterpolate,
            CGColorRenderingIntent intent)),
    function(
        CGDataProviderRef,
        CGDataProviderCreateWithData,(
            void *info,
            const void *data,
            size_t size,
            CGDataProviderReleaseDataCallback releaseData)),
)

//------------------------------------------------------------------------------
