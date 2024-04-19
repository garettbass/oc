#pragma once
#include "foundation.h"

//------------------------------------------------------------------------------

oc_framework(CoreGraphics)

//------------------------------------------------------------------------------

typedef enum CGBitmapInfo {
    CGBitmapAlphaInfoMask     = 0x1F,

    CGBitmapFloatInfoMask     = 0xF00,
    CGBitmapFloatComponents   = (1 << 8),

    CGBitmapByteOrderMask     = 0x7000,  // CGImageByteOrderMask
    CGBitmapByteOrderDefault  = 0 << 12, // CGImageByteOrderDefault
    CGBitmapByteOrder16Little = 1 << 12, // CGImageByteOrder16Little
    CGBitmapByteOrder32Little = 2 << 12, // CGImageByteOrder32Little
    CGBitmapByteOrder16Big    = 3 << 12, // CGImageByteOrder16Big
    CGBitmapByteOrder32Big    = 4 << 12, // CGImageByteOrder32Big
} CGBitmapInfo;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

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

typedef enum CGPathElementType {
    kCGPathElementMoveToPoint,
    kCGPathElementAddLineToPoint,
    kCGPathElementAddQuadCurveToPoint,
    kCGPathElementAddCurveToPoint,
    kCGPathElementCloseSubpath
} CGPathElementType;

//------------------------------------------------------------------------------

typedef struct CGAffineTransform {
    CGFloat a, b, c, d;
    CGFloat tx, ty;
} CGAffineTransform;

typedef struct CGContext CGContext;

typedef struct CGColor CGColor;

typedef struct CGColorSpace CGColorSpace;

typedef struct CGDataProvider CGDataProvider;

typedef struct CGDisplayMode CGDisplayMode;

typedef void (*CGDataProviderReleaseDataCallback)(
    void*       info,
    const void* data,
    size_t      size);

typedef unsigned short CGFontIndex;

typedef CGFontIndex CGGlyph;

typedef struct CGImage CGImage;

typedef struct CGPathElement {
    CGPathElementType type;
    CGPoint*          points;
} CGPathElement;

typedef struct CGPath CGPath;

//------------------------------------------------------------------------------

typedef void (*CGPathApplierFunction)(void* info, const CGPathElement* element);

typedef void (*CGBitmapContextReleaseDataCallback)(void* releaseInfo, void* data);

//------------------------------------------------------------------------------

oc_import(
    CoreGraphics,

    function(
        CGColor*,
        CGColorCreateGenericRGB,(CGFloat r, CGFloat g, CGFloat b, CGFloat a)),

    function(
        CGError,
        CGAssociateMouseAndMouseCursorPosition,(int connected)),

    function(CGColorSpace*,CGColorSpaceCreateWithName,(NSString* name)),

    pointer(NSString*,kCGColorSpaceGenericGray),

    pointer(NSString*,kCGColorSpaceGenericRGB),

    function(
        CGContext*,
        CGBitmapContextCreateWithData,(
            void*                              data,
            size_t                             width,
            size_t                             height,
            size_t                             bitsPerComponent,
            size_t                             bytesPerRow,
            CGColorSpace*                      space,
            uint32_t                           bitmapInfo,
            CGBitmapContextReleaseDataCallback releaseCallback,
            void*                              releaseInfo)),

    function(
        void,
        CGContextSetTextPosition,(CGContext*, CGFloat x, CGFloat y)),

    function(
        void,
        CGContextSetRGBFillColor,(CGContext*, CGFloat r, CGFloat g, CGFloat b, CGFloat a)),

    function(
        void,
        CGContextFillRect,(CGContext*, CGRect)),

    function(
        void,
        CGContextFlush,(CGContext*)),

    function(
        unsigned,
        CGMainDisplayID,(void)),

    function(
        CGDisplayMode*,
        CGDisplayCopyDisplayMode,(unsigned display)),

    function(
        double,
        CGDisplayModeGetRefreshRate,(CGDisplayMode*)),

    function(
        void,
        CGDisplayModeRelease,(CGDisplayMode*)),

    function(
        CGImage*,
        CGImageCreate,(
            size_t                 width,
            size_t                 height,
            size_t                 bitsPerComponent,
            size_t                 bitsPerPixel,
            size_t                 bytesPerRow,
            CGColorSpace*          space,
            CGBitmapInfo           bitmapInfo,
            CGDataProvider*        provider,
            const CGFloat*         decode,
            bool                   shouldInterpolate,
            CGColorRenderingIntent intent)),

    function(
        CGDataProvider*,
        CGDataProviderCreateWithData,(
            void*                             info,
            const void*                       data,
            size_t                            size,
            CGDataProviderReleaseDataCallback releaseData)),

    function(
        void,
        CGPathApply,(
            CGPath*               path,
            void*                 info,
            CGPathApplierFunction function)),

    function(
        CGPath*,
        CGPathCreateMutable,(void)),

    function(
        void,
        CGPathAddRect,(CGPath*, const CGAffineTransform*, CGRect)),
)

//------------------------------------------------------------------------------
