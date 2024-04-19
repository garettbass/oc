#pragma once
#include "foundation.h"

//------------------------------------------------------------------------------

oc_framework(QuartzCore)

oc_class(CAMetalDrawable);
oc_class(CAMetalLayer);

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_framework(MetalKit)

oc_class(MTKView);

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_framework(Metal)

oc_class(MTLArray);
oc_class(MTLBuffer);
oc_class(MTLCommandBuffer);
oc_class(MTLCommandQueue);
oc_class(MTLCompileOptions);
oc_class(MTLDepthStencilDescriptor);
oc_class(MTLDepthStencilState);
oc_class(MTLDevice);
oc_class(MTLFunction);
oc_class(MTLLibrary);
oc_class(MTLRenderCommandEncoder);
oc_class(MTLRenderPassAttachmentDescriptor);
oc_class(MTLRenderPassColorAttachmentDescriptor);
oc_class(MTLRenderPassDepthAttachmentDescriptor);
oc_class(MTLRenderPassDescriptor);
oc_class(MTLRenderPassStencilAttachmentDescriptor);
oc_class(MTLRenderPipelineColorAttachmentDescriptor);
oc_class(MTLRenderPipelineDescriptor);
oc_class(MTLRenderPipelineState);
oc_class(MTLSamplerDescriptor);
oc_class(MTLSamplerState);
oc_class(MTLStencilDescriptor);
oc_class(MTLTexture);
oc_class(MTLTextureDescriptor);
oc_class(MTLVertexAttributeDescriptor);
oc_class(MTLVertexBufferLayoutDescriptor);
oc_class(MTLVertexDescriptor);

oc_import(Metal, function(MTLDevice*,MTLCreateSystemDefaultDevice,(void)))

//------------------------------------------------------------------------------

typedef enum MTLBlendFactor {
    MTLBlendFactor_Zero                     =  0,
    MTLBlendFactor_One                      =  1,
    MTLBlendFactor_SourceColor              =  2,
    MTLBlendFactor_OneMinusSourceColor      =  3,
    MTLBlendFactor_SourceAlpha              =  4,
    MTLBlendFactor_OneMinusSourceAlpha      =  5,
    MTLBlendFactor_DestinationColor         =  6,
    MTLBlendFactor_OneMinusDestinationColor =  7,
    MTLBlendFactor_DestinationAlpha         =  8,
    MTLBlendFactor_OneMinusDestinationAlpha =  9,
    MTLBlendFactor_SourceAlphaSaturated     = 10,
    MTLBlendFactor_BlendColor               = 11,
    MTLBlendFactor_OneMinusBlendColor       = 12,
    MTLBlendFactor_BlendAlpha               = 13,
    MTLBlendFactor_OneMinusBlendAlpha       = 14,
    MTLBlendFactor_Source1Color             = 15,
    MTLBlendFactor_OneMinusSource1Color     = 16,
    MTLBlendFactor_Source1Alpha             = 17,
    MTLBlendFactor_OneMinusSource1Alpha     = 18,
} MTLBlendFactor;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLBlendOperation {
    MTLBlendOperation_Add = 0,
    MTLBlendOperation_Subtract = 1,
    MTLBlendOperation_ReverseSubtract = 2,
    MTLBlendOperation_Min = 3,
    MTLBlendOperation_Max = 4,
} MTLBlendOperation;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLColorWriteMask {
    MTLColorWriteMask_None  = 0,
    MTLColorWriteMask_Red   = 0x1 << 3,
    MTLColorWriteMask_Green = 0x1 << 2,
    MTLColorWriteMask_Blue  = 0x1 << 1,
    MTLColorWriteMask_Alpha = 0x1 << 0,
    MTLColorWriteMask_All   = 0xf
} MTLColorWriteMask;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLCompareFunction {
    MTLCompareFunction_Never = 0,
    MTLCompareFunction_Less = 1,
    MTLCompareFunction_Equal = 2,
    MTLCompareFunction_LessEqual = 3,
    MTLCompareFunction_Greater = 4,
    MTLCompareFunction_NotEqual = 5,
    MTLCompareFunction_GreaterEqual = 6,
    MTLCompareFunction_Always = 7,
} MTLCompareFunction;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLCPUCacheMode {
    MTLCPUCacheMode_DefaultCache  = 0,
    MTLCPUCacheMode_WriteCombined = 1,
} MTLCPUCacheMode;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLCullMode {
    MTLCullMode_None  = 0,
    MTLCullMode_Front = 1,
    MTLCullMode_Back  = 2,
} MTLCullMode;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLDepthClipMode {
    MTLDepthClipMode_Clip  = 0,
    MTLDepthClipMode_Clamp = 1,
} MTLDepthClipMode;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLDispatchType {
    MTLDispatchTypeSerial     = 0,
    MTLDispatchTypeConcurrent = 1,
} MTLDispatchType;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLIndexType {
    MTLIndexType_UInt16 = 0,
    MTLIndexType_UInt32 = 1,
} MTLIndexType;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLLanguageVersion {
    MTLLanguageVersion_Auto = 0,
    MTLLanguageVersion_v1_0 = (1 << 16) + 0,
    MTLLanguageVersion_v1_1 = (1 << 16) + 1,
    MTLLanguageVersion_v1_2 = (1 << 16) + 2,
    MTLLanguageVersion_v2_0 = (2 << 16) + 0,
} MTLLanguageVersion;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLLoadAction {
    MTLLoadAction_DontCare = 0,
    MTLLoadAction_Load     = 1,
    MTLLoadAction_Clear    = 2,
} MTLLoadAction;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLPixelFormat {
    MTLPixelFormat_Invalid                = 0,

    /* Normal 8 bit formats */
    MTLPixelFormat_A8Unorm                = 1,
    MTLPixelFormat_R8Unorm                = 10,
    MTLPixelFormat_R8Unorm_sRGB           = 11,
    MTLPixelFormat_R8Snorm                = 12,
    MTLPixelFormat_R8Uint                 = 13,
    MTLPixelFormat_R8Sint                 = 14,

    /* Normal 16 bit formats */
    MTLPixelFormat_R16Unorm               = 20,
    MTLPixelFormat_R16Snorm               = 22,
    MTLPixelFormat_R16Uint                = 23,
    MTLPixelFormat_R16Sint                = 24,
    MTLPixelFormat_R16Float               = 25,

    MTLPixelFormat_RG8Unorm               = 30,
    MTLPixelFormat_RG8Unorm_sRGB          = 31,
    MTLPixelFormat_RG8Snorm               = 32,
    MTLPixelFormat_RG8Uint                = 33,
    MTLPixelFormat_RG8Sint                = 34,

    /* Packed 16 bit formats */
    MTLPixelFormat_B5G6R5Unorm            = 40,
    MTLPixelFormat_A1BGR5Unorm            = 41,
    MTLPixelFormat_ABGR4Unorm             = 42,
    MTLPixelFormat_BGR5A1Unorm            = 43,

    /* Normal 32 bit formats */
    MTLPixelFormat_R32Uint                = 53,
    MTLPixelFormat_R32Sint                = 54,
    MTLPixelFormat_R32Float               = 55,

    MTLPixelFormat_RG16Unorm              = 60,
    MTLPixelFormat_RG16Snorm              = 62,
    MTLPixelFormat_RG16Uint               = 63,
    MTLPixelFormat_RG16Sint               = 64,
    MTLPixelFormat_RG16Float              = 65,

    MTLPixelFormat_RGBA8Unorm             = 70,
    MTLPixelFormat_RGBA8Unorm_sRGB        = 71,
    MTLPixelFormat_RGBA8Snorm             = 72,
    MTLPixelFormat_RGBA8Uint              = 73,
    MTLPixelFormat_RGBA8Sint              = 74,

    MTLPixelFormat_BGRA8Unorm             = 80,
    MTLPixelFormat_BGRA8Unorm_sRGB        = 81,

    /* Packed 32 bit formats */
    MTLPixelFormat_RGB10A2Unorm           = 90,
    MTLPixelFormat_RGB10A2Uint            = 91,

    MTLPixelFormat_RG11B10Float           = 92,
    MTLPixelFormat_RGB9E5Float            = 93,

    MTLPixelFormat_BGR10_XR               = 554,
    MTLPixelFormat_BGR10_XR_sRGB          = 555,

    /* Normal 64 bit formats */
    MTLPixelFormat_RG32Uint               = 103,
    MTLPixelFormat_RG32Sint               = 104,
    MTLPixelFormat_RG32Float              = 105,

    MTLPixelFormat_RGBA16Unorm            = 110,
    MTLPixelFormat_RGBA16Snorm            = 112,
    MTLPixelFormat_RGBA16Uint             = 113,
    MTLPixelFormat_RGBA16Sint             = 114,
    MTLPixelFormat_RGBA16Float            = 115,

    MTLPixelFormat_BGRA10_XR              = 552,
    MTLPixelFormat_BGRA10_XR_sRGB         = 553,

    /* Normal 128 bit formats */
    MTLPixelFormat_RGBA32Uint             = 123,
    MTLPixelFormat_RGBA32Sint             = 124,
    MTLPixelFormat_RGBA32Float            = 125,

    /* S3TC/DXT */
    MTLPixelFormat_BC1_RGBA               = 130,
    MTLPixelFormat_BC1_RGBA_sRGB          = 131,
    MTLPixelFormat_BC2_RGBA               = 132,
    MTLPixelFormat_BC2_RGBA_sRGB          = 133,
    MTLPixelFormat_BC3_RGBA               = 134,
    MTLPixelFormat_BC3_RGBA_sRGB          = 135,

    /* RGTC */
    MTLPixelFormat_BC4_RUnorm             = 140,
    MTLPixelFormat_BC4_RSnorm             = 141,
    MTLPixelFormat_BC5_RGUnorm            = 142,
    MTLPixelFormat_BC5_RGSnorm            = 143,

    /* BPTC */
    MTLPixelFormat_BC6H_RGBFloat          = 150,
    MTLPixelFormat_BC6H_RGBUfloat         = 151,
    MTLPixelFormat_BC7_RGBAUnorm          = 152,
    MTLPixelFormat_BC7_RGBAUnorm_sRGB     = 153,

    /* PVRTC */
    MTLPixelFormat_PVRTC_RGB_2BPP         = 160,
    MTLPixelFormat_PVRTC_RGB_2BPP_sRGB    = 161,
    MTLPixelFormat_PVRTC_RGB_4BPP         = 162,
    MTLPixelFormat_PVRTC_RGB_4BPP_sRGB    = 163,
    MTLPixelFormat_PVRTC_RGBA_2BPP        = 164,
    MTLPixelFormat_PVRTC_RGBA_2BPP_sRGB   = 165,
    MTLPixelFormat_PVRTC_RGBA_4BPP        = 166,
    MTLPixelFormat_PVRTC_RGBA_4BPP_sRGB   = 167,

    /* ETC2 */
    MTLPixelFormat_EAC_R11Unorm           = 170,
    MTLPixelFormat_EAC_R11Snorm           = 172,
    MTLPixelFormat_EAC_RG11Unorm          = 174,
    MTLPixelFormat_EAC_RG11Snorm          = 176,
    MTLPixelFormat_EAC_RGBA8              = 178,
    MTLPixelFormat_EAC_RGBA8_sRGB         = 179,

    MTLPixelFormat_ETC2_RGB8              = 180,
    MTLPixelFormat_ETC2_RGB8_sRGB         = 181,
    MTLPixelFormat_ETC2_RGB8A1            = 182,
    MTLPixelFormat_ETC2_RGB8A1_sRGB       = 183,

    /* ASTC */
    MTLPixelFormat_ASTC_4x4_sRGB          = 186,
    MTLPixelFormat_ASTC_5x4_sRGB          = 187,
    MTLPixelFormat_ASTC_5x5_sRGB          = 188,
    MTLPixelFormat_ASTC_6x5_sRGB          = 189,
    MTLPixelFormat_ASTC_6x6_sRGB          = 190,
    MTLPixelFormat_ASTC_8x5_sRGB          = 192,
    MTLPixelFormat_ASTC_8x6_sRGB          = 193,
    MTLPixelFormat_ASTC_8x8_sRGB          = 194,
    MTLPixelFormat_ASTC_10x5_sRGB         = 195,
    MTLPixelFormat_ASTC_10x6_sRGB         = 196,
    MTLPixelFormat_ASTC_10x8_sRGB         = 197,
    MTLPixelFormat_ASTC_10x10_sRGB        = 198,
    MTLPixelFormat_ASTC_12x10_sRGB        = 199,
    MTLPixelFormat_ASTC_12x12_sRGB        = 200,

    MTLPixelFormat_ASTC_4x4_LDR           = 204,
    MTLPixelFormat_ASTC_5x4_LDR           = 205,
    MTLPixelFormat_ASTC_5x5_LDR           = 206,
    MTLPixelFormat_ASTC_6x5_LDR           = 207,
    MTLPixelFormat_ASTC_6x6_LDR           = 208,
    MTLPixelFormat_ASTC_8x5_LDR           = 210,
    MTLPixelFormat_ASTC_8x6_LDR           = 211,
    MTLPixelFormat_ASTC_8x8_LDR           = 212,
    MTLPixelFormat_ASTC_10x5_LDR          = 213,
    MTLPixelFormat_ASTC_10x6_LDR          = 214,
    MTLPixelFormat_ASTC_10x8_LDR          = 215,
    MTLPixelFormat_ASTC_10x10_LDR         = 216,
    MTLPixelFormat_ASTC_12x10_LDR         = 217,
    MTLPixelFormat_ASTC_12x12_LDR         = 218,

    MTLPixelFormat_GBGR422                = 240,
    MTLPixelFormat_BGRG422                = 241,

    /* Depth */
    MTLPixelFormat_Depth16Unorm           = 250,
    MTLPixelFormat_Depth32Float           = 252,

    /* Stencil */
    MTLPixelFormat_Stencil8               = 253,

    /* Depth Stencil */
    MTLPixelFormat_Depth24Unorm_Stencil8  = 255,
    MTLPixelFormat_Depth32Float_Stencil8  = 260,

    MTLPixelFormat_X32_Stencil8           = 261,
    MTLPixelFormat_X24_Stencil8           = 262,
} MTLPixelFormat;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLPrimitiveTopologyClass {
    MTLPrimitiveTopologyClass_Unspecified = 0,
    MTLPrimitiveTopologyClass_Point = 1,
    MTLPrimitiveTopologyClass_Line = 2,
    MTLPrimitiveTopologyClass_Triangle = 3,
} MTLPrimitiveTopologyClass;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLPrimitiveType {
    MTLPrimitiveType_Point = 0,
    MTLPrimitiveType_Line = 1,
    MTLPrimitiveType_LineStrip = 2,
    MTLPrimitiveType_Triangle = 3,
    MTLPrimitiveType_TriangleStrip = 4,
} MTLPrimitiveType;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLResourceOptions {
    MTLResourceOptions_DefaultCache  = 0 << 0,
    MTLResourceOptions_WriteCombined = 1 << 0,

    MTLResourceOptions_Shared     = 0 << 4,
    MTLResourceOptions_Managed    = 1 << 4,
    MTLResourceOptions_Private    = 2 << 4,
    MTLResourceOptions_Memoryless = 3 << 4,

    MTLResourceOptions_HazardTrackingModeUntracked  = 1 << 8,
} MTLResourceOptions;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLSamplerAddressMode {
    MTLSamplerAddressMode_ClampToEdge        = 0,
    MTLSamplerAddressMode_MirrorClampToEdge  = 1,
    MTLSamplerAddressMode_Repeat             = 2,
    MTLSamplerAddressMode_MirrorRepeat       = 3,
    MTLSamplerAddressMode_ClampToZero        = 4,
    MTLSamplerAddressMode_ClampToBorderColor = 5,
} MTLSamplerAddressMode;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLSamplerMinMagFilter {
    MTLSamplerMinMagFilter_Nearest = 0,
    MTLSamplerMinMagFilter_Linear  = 1,
} MTLSamplerMinMagFilter;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLSamplerMipFilter {
    MTLSamplerMipFilter_NotMipmapped = 0,
    MTLSamplerMipFilter_Nearest      = 1,
    MTLSamplerMipFilter_Linear       = 2,
} MTLSamplerMipFilter;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLSamplerBorderColor {
    MTLSamplerBorderColor_TransparentBlack = 0,
    MTLSamplerBorderColor_OpaqueBlack      = 1,
    MTLSamplerBorderColor_OpaqueWhite      = 2,
} MTLSamplerBorderColor;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLStencilOperation {
    MTLStencilOperation_Keep = 0,
    MTLStencilOperation_Zero = 1,
    MTLStencilOperation_Replace = 2,
    MTLStencilOperation_IncrementClamp = 3,
    MTLStencilOperation_DecrementClamp = 4,
    MTLStencilOperation_Invert = 5,
    MTLStencilOperation_IncrementWrap = 6,
    MTLStencilOperation_DecrementWrap = 7,
} MTLStencilOperation;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLStorageMode {
    MTLStorageMode_Shared     = 0,
    MTLStorageMode_Managed    = 1,
    MTLStorageMode_Private    = 2,
    MTLStorageMode_Memoryless = 3,
} MTLStorageMode;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLStoreAction {
    MTLStoreAction_DontCare                   = 0,
    MTLStoreAction_Store                      = 1,
    MTLStoreAction_MultisampleResolve         = 2,
    MTLStoreAction_StoreAndMultisampleResolve = 3,
    MTLStoreAction_Unknown                    = 4,
    MTLStoreAction_CustomSampleDepthStore     = 5,
} MTLStoreAction;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLTessellationPartitionMode {
    MTLTessellationPartitionMode_Pow2           = 0,
    MTLTessellationPartitionMode_Integer        = 1,
    MTLTessellationPartitionMode_FractionalOdd  = 2,
    MTLTessellationPartitionMode_FractionalEven = 3,
} MTLTessellationPartitionMode;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLTessellationFactorStepFunction {
    MTLTessellationFactorStepFunction_Constant               = 0,
    MTLTessellationFactorStepFunction_PerPatch               = 1,
    MTLTessellationFactorStepFunction_PerInstance            = 2,
    MTLTessellationFactorStepFunction_PerPatchAndPerInstance = 3,
} MTLTessellationFactorStepFunction;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLTessellationFactorFormat {
    MTLTessellationFactorFormat_Half = 0,
} MTLTessellationFactorFormat;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLTessellationControlPointIndexType {
    MTLTessellationControlPointIndexType_None   = 0,
    MTLTessellationControlPointIndexType_UInt16 = 1,
    MTLTessellationControlPointIndexType_UInt32 = 2,
} MTLTessellationControlPointIndexType;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLTextureType {
    MTLTextureType_Texture1D            = 0,
    MTLTextureType_Texture1DArray       = 1,
    MTLTextureType_Texture2D            = 2,
    MTLTextureType_Texture2DArray       = 3,
    MTLTextureType_Texture2DMultisample = 4,
    MTLTextureType_TextureCube          = 5,
    MTLTextureType_TextureCubeArray     = 6,
    MTLTextureType_Texture3D            = 7,
} MTLTextureType;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLTextureUsage {
    MTLTextureUsage_Unknown         = 0x0000,
    MTLTextureUsage_ShaderRead      = 0x0001,
    MTLTextureUsage_ShaderWrite     = 0x0002,
    MTLTextureUsage_ShaderReadWrite = 0x0003,
    MTLTextureUsage_RenderTarget    = 0x0004,
    MTLTextureUsage_PixelFormatView = 0x0010,
} MTLTextureUsage;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLTriangleFillMode {
    MTLTriangleFillMode_Fill  = 0,
    MTLTriangleFillMode_Lines = 1,
} MTLTriangleFillMode;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLVertexFormat {
    MTLVertexFormat_Invalid               = 0,

    MTLVertexFormat_UChar2                = 1,
    MTLVertexFormat_UChar3                = 2,
    MTLVertexFormat_UChar4                = 3,

    MTLVertexFormat_Char2                 = 4,
    MTLVertexFormat_Char3                 = 5,
    MTLVertexFormat_Char4                 = 6,

    MTLVertexFormat_UChar2Normalized      = 7,
    MTLVertexFormat_UChar3Normalized      = 8,
    MTLVertexFormat_UChar4Normalized      = 9,

    MTLVertexFormat_Char2Normalized       = 10,
    MTLVertexFormat_Char3Normalized       = 11,
    MTLVertexFormat_Char4Normalized       = 12,

    MTLVertexFormat_UShort2               = 13,
    MTLVertexFormat_UShort3               = 14,
    MTLVertexFormat_UShort4               = 15,

    MTLVertexFormat_Short2                = 16,
    MTLVertexFormat_Short3                = 17,
    MTLVertexFormat_Short4                = 18,

    MTLVertexFormat_UShort2Normalized     = 19,
    MTLVertexFormat_UShort3Normalized     = 20,
    MTLVertexFormat_UShort4Normalized     = 21,

    MTLVertexFormat_Short2Normalized      = 22,
    MTLVertexFormat_Short3Normalized      = 23,
    MTLVertexFormat_Short4Normalized      = 24,

    MTLVertexFormat_Half2                 = 25,
    MTLVertexFormat_Half3                 = 26,
    MTLVertexFormat_Half4                 = 27,

    MTLVertexFormat_Float                 = 28,
    MTLVertexFormat_Float2                = 29,
    MTLVertexFormat_Float3                = 30,
    MTLVertexFormat_Float4                = 31,

    MTLVertexFormat_Int                   = 32,
    MTLVertexFormat_Int2                  = 33,
    MTLVertexFormat_Int3                  = 34,
    MTLVertexFormat_Int4                  = 35,

    MTLVertexFormat_UInt                  = 36,
    MTLVertexFormat_UInt2                 = 37,
    MTLVertexFormat_UInt3                 = 38,
    MTLVertexFormat_UInt4                 = 39,

    MTLVertexFormat_Int1010102Normalized  = 40,
    MTLVertexFormat_UInt1010102Normalized = 41,
} MTLVertexFormat;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLVertexStepFunction {
    MTLVertexStepFunction_Constant             = 0,
    MTLVertexStepFunction_PerVertex            = 1,
    MTLVertexStepFunction_PerInstance          = 2,
    MTLVertexStepFunction_PerPatch             = 3,
    MTLVertexStepFunction_PerPatchControlPoint = 4,
} MTLVertexStepFunction;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLVisibilityResultMode {
    MTLVisibilityResultMode_Disabled = 0,
    MTLVisibilityResultMode_Boolean  = 1,
    MTLVisibilityResultMode_Counting = 2,
} MTLVisibilityResultMode;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef enum MTLWinding {
    MTLWinding_Clockwise        = 0,
    MTLWinding_CounterClockwise = 1,
} MTLWinding;

//------------------------------------------------------------------------------

typedef struct MTLClearColor {
    double red;
    double green;
    double blue;
    double alpha;
} MTLClearColor;

typedef struct MTLOrigin {
    NSUInteger x;
    NSUInteger y;
    NSUInteger z;
} MTLOrigin;

typedef struct MTLSize {
    NSUInteger width;
    NSUInteger height;
    NSUInteger depth;
} MTLSize;

typedef struct MTLRegion {
    MTLOrigin origin;
    MTLSize   size;
} MTLRegion;

typedef struct MTLScissorRect {
    NSUInteger x;
    NSUInteger y;
    NSUInteger width;
    NSUInteger height;
} MTLScissorRect;

typedef struct MTLViewport {
    double originX;
    double originY;
    double width;
    double height;
    double znear;
    double zfar;
} MTLViewport;

//------------------------------------------------------------------------------

oc_interface(
    CAMetalDrawable,
    obj(MTLTexture*, texture),
    obj(CAMetalLayer*, layer),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    MTKView,
    obj(MTKView*,
        initWithFrame,NSRect,
        device,MTLDevice*),
    obj(CAMetalDrawable*,
        currentDrawable),
    obj(MTLRenderPassDescriptor*,
        currentRenderPassDescriptor),
    obj(void, draw),
    obj(void, setDepthStencilPixelFormat,MTLPixelFormat),
    obj(void, setPaused,bool),
    obj(void, setSampleCount,NSUInteger),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    MTLArray,
    obj(id,     objectAtIndexedSubscript,NSUInteger),
    obj(void,   setObject,MTLRenderPassColorAttachmentDescriptor*,
                atIndexedSubscript,NSUInteger),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    MTLBuffer,
    obj(MTLTexture*,
        newTextureWithDescriptor,MTLTextureDescriptor*,
        offset,NSUInteger,
        bytesPerRow,NSUInteger),
    obj(void*,      contents),
    obj(void,       didModifyRange,NSRange),
    obj(NSUInteger, length),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    MTLCommandBuffer,
    obj(MTLRenderCommandEncoder*,
        renderCommandEncoderWithDescriptor,MTLRenderPassDescriptor*),
    obj(void,       commit),
    obj(void,       enqueue),
    obj(NSError*,   error),
    obj(void,       presentDrawable,id),
    obj(void,       presentDrawable,id,
                    afterMinimumDuration,double),
    obj(void,       presentDrawable,id,
                    atTime,double),
    obj(void,       waitUntilCompleted),
    obj(void,       waitUntilScheduled),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    MTLCommandQueue,
    obj(NSString*,         label),
    obj(MTLDevice*,        device),
    obj(MTLCommandBuffer*, commandBuffer),
    obj(MTLCommandBuffer*, commandBufferWithUnretainedReferences),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    MTLCompileOptions,
    obj(void, setFastMathEnabled,bool),
    obj(void, setLanguageVersion,MTLLanguageVersion),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    MTLStencilDescriptor,
    obj(void, setStencilCompareFunction,MTLCompareFunction),
    obj(void, setStencilFailureOperation,MTLStencilOperation),
    obj(void, setDepthFailureOperation,MTLStencilOperation),
    obj(void, setDepthStencilPassOperation,MTLStencilOperation),
    obj(void, setReadMask,unsigned),
    obj(void, setWriteMask,unsigned),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    MTLDepthStencilDescriptor,
    obj(void, setDepthCompareFunction,MTLCompareFunction),
    obj(void, setDepthWriteEnabled,bool),
    obj(void, setFrontFaceStencil,MTLStencilDescriptor*),
    obj(void, setBackFaceStencil,MTLStencilDescriptor*),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    MTLDevice,
    obj(NSString*, name),
    obj(MTLBuffer*,
        newBufferWithLength,NSUInteger,
        options,MTLResourceOptions),
    obj(MTLBuffer*,
        newBufferWithBytes,const void*,
        length,NSUInteger,
        options,MTLResourceOptions),
    obj(MTLCommandQueue*,
        newCommandQueue),
    obj(MTLDepthStencilState*,
        newDepthStencilStateWithDescriptor,MTLDepthStencilDescriptor*),
    obj(MTLLibrary*,
        newLibraryWithData,const void*,
        error,NSError**),
    obj(MTLLibrary*,
        newLibraryWithSource,NSString*,
        options,MTLCompileOptions*,
        error,NSError**),
    obj(MTLRenderPipelineState*,
        newRenderPipelineStateWithDescriptor,MTLRenderPipelineDescriptor*,
        error, NSError**),
    obj(MTLSamplerState*,
        newSamplerStateWithDescriptor,MTLSamplerDescriptor*),
    obj(MTLTexture*,
        newTextureWithDescriptor,MTLTextureDescriptor*),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    MTLLibrary,
    obj(MTLFunction*, newFunctionWithName,NSString*),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    MTLRenderPassAttachmentDescriptor,
    obj(MTLTexture*, texture),  obj(void, setTexture,void*),
    obj(NSUInteger,  slice),    obj(void, setSlice,NSUInteger),
    obj(NSUInteger,  level),    obj(void, setLevel,NSUInteger),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    MTLRenderPassColorAttachmentDescriptor,
    obj(void, setLoadAction,MTLLoadAction),
    obj(void, setClearColor,MTLClearColor),

    obj(void, setStoreAction,MTLStoreAction),
    obj(void, setResolveTexture,void*),
    obj(void, setResolveSlice,NSUInteger),
    obj(void, setResolveLevel,NSUInteger),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    MTLRenderPassDepthAttachmentDescriptor,
    obj(void, setLoadAction,MTLLoadAction),
    obj(void, setClearDepth,double),

    obj(void, setStoreAction,MTLStoreAction),
    obj(void, setResolveTexture,void*),
    obj(void, setResolveSlice,NSUInteger),
    obj(void, setResolveLevel,NSUInteger),
    obj(void, setResolveDepthPlane,NSUInteger),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    MTLRenderPassStencilAttachmentDescriptor,
    obj(void, setLoadAction,MTLLoadAction),
    obj(void, setClearStencil,unsigned),

    obj(void, setStoreAction,MTLStoreAction),
    obj(void, setResolveTexture,void*),
    obj(void, setResolveSlice,NSUInteger),
    obj(void, setResolveLevel,NSUInteger),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    MTLRenderPassDescriptor,
    obj(MTLArray*,                                 colorAttachments),
    obj(MTLRenderPassDepthAttachmentDescriptor*,   depthAttachment),
    obj(MTLRenderPassStencilAttachmentDescriptor*, stencilAttachment),
    obj(void, setDepthAttachment,MTLRenderPassDepthAttachmentDescriptor*),
    obj(void, setStencilAttachment,MTLRenderPassStencilAttachmentDescriptor*),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    MTLRenderCommandEncoder,
    obj(void, drawPrimitives,MTLPrimitiveType,
              vertexStart,NSUInteger,
              vertexCount,NSUInteger,
              instanceCount,NSUInteger,
              baseInstance,NSUInteger),
    obj(void, drawIndexedPrimitives,MTLPrimitiveType,
              indexCount,NSUInteger,
              indexType,MTLIndexType,
              indexBuffer,void*,
              indexBufferOffset,NSUInteger,
              instanceCount,NSUInteger,
              baseVertex,NSUInteger,
              baseInstance,NSUInteger),
    obj(void, endEncoding),
    obj(void, setCullMode,MTLCullMode),
    obj(void, setFrontFacingWinding,MTLWinding),
    obj(void, setRenderPipelineState,void*),
    obj(void, setDepthStencilState,void*),
    obj(void, setViewport,MTLViewport),
    obj(void, setScissorRect,MTLScissorRect),

    obj(void,
        setVertexBuffer,MTLBuffer*,
        offset,NSUInteger, 
        atIndex,NSUInteger),
    obj(void,
        setVertexTexture,MTLTexture*,
        atIndex,NSUInteger),
    obj(void,
        setVertexSamplerState,MTLSamplerState*, 
        atIndex,NSUInteger),

    obj(void,
        setFragmentBuffer,MTLBuffer*,
        offset,NSUInteger, 
        atIndex,NSUInteger),
    obj(void,
        setFragmentTexture,MTLTexture*,
        atIndex,NSUInteger),
    obj(void,
        setFragmentSamplerState,MTLSamplerState*, 
        atIndex,NSUInteger),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    MTLRenderPipelineColorAttachmentDescriptor,
    obj(void, setPixelFormat,MTLPixelFormat),
    obj(void, setBlendingEnabled,bool),

    obj(void, setSourceRGBBlendFactor,MTLBlendFactor),
    obj(void, setDestinationRGBBlendFactor,MTLBlendFactor),
    obj(void, setRgbBlendOperation,MTLBlendOperation),

    obj(void, setSourceAlphaBlendFactor,MTLBlendFactor),
    obj(void, setDestinationAlphaBlendFactor,MTLBlendFactor),
    obj(void, setAlphaBlendOperation,MTLBlendOperation),

    obj(void, setWriteMask,MTLColorWriteMask),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    MTLRenderPipelineDescriptor,
    obj(MTLArray*, colorAttachments),
    obj(void, setVertexDescriptor,MTLVertexDescriptor*),
    obj(void, setVertexFunction,MTLFunction*),
    obj(void, setFragmentFunction,MTLFunction*),
    obj(void, setSampleCount,NSUInteger),
    obj(void, setAlphaToCoverageEnabled,bool),
    obj(void, setAlphaToOneEnabled,bool),
    obj(void, setRasterizationEnabled,bool),
    obj(void, setDepthAttachmentPixelFormat,MTLPixelFormat),
    obj(void, setStencilAttachmentPixelFormat,MTLPixelFormat),
    obj(void, setInputPrimitiveTopology,MTLPrimitiveTopologyClass),
    obj(void, setTessellationPartitionMode,MTLTessellationPartitionMode),
    obj(void, setMaxTessellationFactor,NSUInteger),
    obj(void, setTessellationFactorScaleEnabled,bool),
    obj(void, setTessellationFactorFormat,MTLTessellationFactorFormat),
    obj(void, setTessellationControlPointIndexType,MTLTessellationControlPointIndexType),
    obj(void, setTessellationFactorStepFunction,MTLTessellationFactorStepFunction),
    obj(void, setTessellationOutputWindingOrder,MTLWinding),
    obj(void, reset),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    MTLSamplerDescriptor,
    obj(void, setMaxAnisotropy,NSUInteger),
    obj(void, setMagFilter,MTLSamplerMinMagFilter),
    obj(void, setMinFilter,MTLSamplerMinMagFilter),
    obj(void, setMipFilter,MTLSamplerMipFilter),
    obj(void, setRAddressMode,MTLSamplerAddressMode),
    obj(void, setSAddressMode,MTLSamplerAddressMode),
    obj(void, setTAddressMode,MTLSamplerAddressMode),
    obj(void, setLodMinClamp,float),
    obj(void, setLodMaxClamp,float),
    obj(void, setBorderColor,MTLSamplerBorderColor),
    obj(void, setNormalizedCoordinates,bool),
    obj(void, setLodAverage,bool),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    MTLTextureDescriptor,
    obj(void, setTextureType,MTLTextureType),
    obj(void, setPixelFormat,MTLPixelFormat),
    obj(void, setWidth,NSUInteger),
    obj(void, setHeight,NSUInteger),
    obj(void, setDepth,NSUInteger),
    obj(void, setMipmapLevelCount,NSUInteger),
    obj(void, setSampleCount,NSUInteger),
    obj(void, setArrayLength,NSUInteger),
    obj(void, setResourceOptions,MTLResourceOptions),
    obj(void, setCpuCacheMode,MTLCPUCacheMode),
    obj(void, setStorageMode,MTLStorageMode),
    obj(void, setUsage,MTLTextureUsage),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    MTLTexture,
    obj(void,
        replaceRegion,MTLRegion,
        mipmapLevel,NSUInteger,
        withBytes,const void*,
        bytesPerRow,NSUInteger),
    obj(void,
        replaceRegion,MTLRegion, 
        mipmapLevel,NSUInteger,
        slice,NSUInteger,
        withBytes,const void *,
        bytesPerRow,NSUInteger,
        bytesPerImage,NSUInteger),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    MTLVertexAttributeDescriptor,
    obj(void, setBufferIndex,NSUInteger),
    obj(void, setFormat,MTLVertexFormat),
    obj(void, setOffset,NSUInteger),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    MTLVertexBufferLayoutDescriptor,
    obj(void, setStepFunction,MTLVertexStepFunction),
    obj(void, setStepRate,NSUInteger),
    obj(void, setStride,NSUInteger),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    MTLVertexDescriptor,
    obj(MTLArray*, attributes),
    obj(MTLArray*, layouts),
    obj(void,      reset),
)

//------------------------------------------------------------------------------
