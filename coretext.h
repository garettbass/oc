#pragma once
#include "coregraphics.h"

//------------------------------------------------------------------------------

oc_framework(CoreText)

//------------------------------------------------------------------------------

typedef enum CTFontOrientation {
    kCTFontOrientationDefault    = 0,
    kCTFontOrientationHorizontal = 1,
    kCTFontOrientationVertical   = 2,
} CTFontOrientation;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum CTFontUIFontType {
    kCTFontUIFontNone                   = -1,
    kCTFontUIFontUser                   =  0,
    kCTFontUIFontUserFixedPitch         =  1,
    kCTFontUIFontSystem                 =  2,
    kCTFontUIFontEmphasizedSystem       =  3,
    kCTFontUIFontSmallSystem            =  4,
    kCTFontUIFontSmallEmphasizedSystem  =  5,
    kCTFontUIFontMiniSystem             =  6,
    kCTFontUIFontMiniEmphasizedSystem   =  7,
    kCTFontUIFontViews                  =  8,
    kCTFontUIFontApplication            =  9,
    kCTFontUIFontLabel                  = 10,
    kCTFontUIFontMenuTitle              = 11,
    kCTFontUIFontMenuItem               = 12,
    kCTFontUIFontMenuItemMark           = 13,
    kCTFontUIFontMenuItemCmdKey         = 14,
    kCTFontUIFontWindowTitle            = 15,
    kCTFontUIFontPushButton             = 16,
    kCTFontUIFontUtilityWindowTitle     = 17,
    kCTFontUIFontAlertHeader            = 18,
    kCTFontUIFontSystemDetail           = 19,
    kCTFontUIFontEmphasizedSystemDetail = 20,
    kCTFontUIFontToolbar                = 21,
    kCTFontUIFontSmallToolbar           = 22,
    kCTFontUIFontMessage                = 23,
    kCTFontUIFontPalette                = 24,
    kCTFontUIFontToolTip                = 25,
    kCTFontUIFontControlContent         = 26,
} CTFontUIFontType;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum CTFontOptions {
    kCTFontOptionsDefault               = 0,
    kCTFontOptionsPreventAutoActivation = 1 << 0,
    kCTFontOptionsPreferSystemFont      = 1 << 2
} CTFontOptions;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum CTFontTableOptions {
    kCTFontTableOptionNoOptions        = 0,
    kCTFontTableOptionExcludeSynthetic = 1,
} CTFontTableOptions;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum CTLineTruncationType {
    kCTLineTruncationStart  = 0,
    kCTLineTruncationEnd    = 1,
    kCTLineTruncationMiddle = 2,
} CTLineTruncationType;

//------------------------------------------------------------------------------

typedef struct CTFont           CTFont;
typedef struct CTFontCollection CTFontCollection;
typedef struct CTFontDescriptor CTFontDescriptor;

typedef struct CTFramesetter    CTFramesetter;
typedef struct CTFrame          CTFrame;
typedef struct CTLine           CTLine;
typedef struct CTRun            CTRun;

//------------------------------------------------------------------------------

oc_import(CoreText,

    function(
        CTFontCollection*,
        CTFontCollectionCreateFromAvailableFonts,(
            NSDictionary* options)),

    function(
        NSArray*,
        CTFontCollectionCreateMatchingFontDescriptors,(
            CTFontCollection* collection)),

    function(
        id,
        CTFontDescriptorCopyAttribute,(
            CTFontDescriptor* descriptor,
            NSString* attribute)),

    pointer(CFString*, kCTFontAttributeName),
    pointer(CFString*, kCTForegroundColorAttributeName),

    /* Font Attributes */
    pointer(NSString*, kCTFontBaselineAdjustAttribute),
    pointer(NSString*, kCTFontCascadeListAttribute),
    pointer(NSString*, kCTFontCharacterSetAttribute),
    pointer(NSString*, kCTFontDisplayNameAttribute),
    pointer(NSString*, kCTFontEnabledAttribute),
    pointer(NSString*, kCTFontFamilyNameAttribute),
    pointer(NSString*, kCTFontFeaturesAttribute),
    pointer(NSString*, kCTFontFeatureSettingsAttribute),
    pointer(NSString*, kCTFontFixedAdvanceAttribute),
    pointer(NSString*, kCTFontFormatAttribute),
    pointer(NSString*, kCTFontLanguagesAttribute),
    pointer(NSString*, kCTFontMacintoshEncodingsAttribute),
    pointer(NSString*, kCTFontMatrixAttribute),
    pointer(NSString*, kCTFontNameAttribute),
    pointer(NSString*, kCTFontOrientationAttribute),
    pointer(NSString*, kCTFontPriorityAttribute),
    pointer(NSString*, kCTFontRegistrationScopeAttribute),
    pointer(NSString*, kCTFontSizeAttribute),
    pointer(NSString*, kCTFontStyleNameAttribute),
    pointer(NSString*, kCTFontTraitsAttribute),
    pointer(NSString*, kCTFontURLAttribute),
    pointer(NSString*, kCTFontVariationAttribute),

    // CTFont \\................................................................

    function(
        CTFont*,
        CTFontCreateWithName,(
            NSString*                name,
            CGFloat                  size,
            const CGAffineTransform* matrix)),

    function(
        CTFont*,
        CTFontCreateUIFontForLanguage,(
            CTFontUIFontType uiType,
            CGFloat          size,
            NSString*        language)),

    function(
        bool,
        CTFontGetGlyphsForCharacters,(
            CTFont*         font,
            const uint16_t* characters,
            CGGlyph*        glyphs,
            signed long     count)),

    function(
        CGFloat,
        CTFontGetAscent,(CTFont* font)),

    function(
        CGFloat,
        CTFontGetDescent,(CTFont* font)),

    function(
        CGFloat,
        CTFontGetLeading,(CTFont* font)),

    function(
        unsigned,
        CTFontGetUnitsPerEm,(CTFont* font)),

    function(
        signed long,
        CTFontGetGlyphCount,(CTFont* font)),

    function(
        CGRect,
        CTFontGetBoundingBox,(CTFont* font)),

    function(
        CGFloat,
        CTFontGetUnderlinePosition,(CTFont* font)),

    function(
        CGFloat,
        CTFontGetUnderlineThickness,(CTFont* font)),

    function(
        CGFloat,
        CTFontGetSlantAngle,(CTFont* font)),

    function(
        CGFloat,
        CTFontGetCapHeight,(CTFont* font)),

    function(
        CGFloat,
        CTFontGetXHeight,(CTFont* font)),

    function(
        CGRect,
        CTFontGetBoundingRectsForGlyphs,(
            CTFont*           font,
            CTFontOrientation orientation,
            const CGGlyph     glyphs,
            CGRect*           boundingRects,
            signed long       count)),

    function(
        CGRect,
        CTFontGetOpticalBoundsForGlyphs,(
            CTFont*        font,
            const CGGlyph* glyphs,
            CGRect*        boundingRects,
            signed long    count,
            CTFontOptions  options)),

    function(
        double,
        CTFontGetAdvancesForGlyphs,(
            CTFont*           font,
            CTFontOrientation orientation,
            const CGGlyph*    glyphs,
            CGSize*           advances,
            signed long       count)),

    function(
        void,
        CTFontGetVerticalTranslationsForGlyphs,(
            CTFont*        font,
            const CGGlyph* glyphs,
            CGSize*        translations,
            signed long    count)),

    function(
        CGPath*,
        CTFontCreatePathForGlyph,(
            CTFont*                  font,
            CGGlyph                  glyph,
            const CGAffineTransform* matrix)),

    function(
        NSArray,
        CTFontCopyDefaultCascadeListForLanguages,(
            CTFont*  font,
            NSArray languagePrefList)),

)

//------------------------------------------------------------------------------

oc_import(CoreText,

    // CTFramesetter \\.........................................................

    function(
        CTFramesetter*,
        CTFramesetterCreateWithAttributedString,(CFAttributedString*)),

    // CTFrame \\...............................................................

    function(
        CTFrame*,
        CTFramesetterCreateFrame,(
            CTFramesetter*,
            CFRange,
            CGPath* path,
            CFDictionary* attributes)),

    function(
        CFRange,
        CTFrameGetVisibleStringRange,(CTFrame*)),

    function(
        CFArray*,
        CTFrameGetLines,(CTFrame*)),

    function(
        void,
        CTFrameDraw,(CTFrame*, CGContext*)),

    // CTLine \\................................................................

    function(
        CTLine*,
        CTLineCreateWithAttributedString,(CFAttributedString*)),

    function(
        CTLine*,
        CTLineCreateTruncatedLine,(
            CTLine*,
            double width,
            CTLineTruncationType truncationType,
            CTLine*              truncationToken)),

    function(
        CTLine*,
        CTLineCreateJustifiedLine,(
            CTLine*,
            CGFloat justificationFactor,
            double  justificationWidth)),

    function(
        CFIndex,
        CTLineGetGlyphCount,(CTLine*)),

    function(
        CFArray*,
        CTLineGetGlyphRuns,(CTLine*)),

    function(
        double,
        CTLineGetPenOffsetForFlush,(
            CTLine*,
            CGFloat flushFactor,
            double  flushWidth)),

    function(
        CGRect,
        CTLineGetImageBounds,(CTLine*, CGContext*)),

    function(
        CFIndex,
        CTLineGetStringIndexForPosition,(CTLine*, CGPoint)),

    function(
        CGFloat,
        CTLineGetOffsetForStringIndex,(
            CTLine*,
            CFIndex  charIndex,
            CGFloat* secondaryOffset)),

    function(
        void,
        CTLineDraw,(CTLine*, CGContext*)),

    // CTRun \\.................................................................

    function(
        CFRange,
        CTRunGetStringRange,(CTRun*)),

    function(
        CFIndex,
        CTRunGetGlyphCount,(CTRun*)),

    function(
        void,
        CTRunGetGlyphs,(CTRun*, CFRange, CGGlyph* buffer)),

    function(
        void,
        CTRunGetPositions,(CTRun*, CFRange, CGPoint* buffer)),

    function(
        void,
        CTRunGetStringIndices,(CTRun*, CFRange, CFIndex* buffer)),

    function(
        CGRect,
        CTRunGetImageBounds,(CTRun*, CGContext*, CFRange)),

) // oc_import(CoreText, ...)

//------------------------------------------------------------------------------
