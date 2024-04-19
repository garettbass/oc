#pragma once
#include "corefoundation.h"

//------------------------------------------------------------------------------

oc_class(NSArray);
oc_class(NSAutoreleasePool);
oc_class(NSBundle);
oc_class(NSData);
oc_class(NSDictionary);
oc_class(NSError);
oc_class(NSMutableArray);
oc_class(NSNotification);
oc_class(NSString);

//------------------------------------------------------------------------------

#if defined(__LP64__) && __LP64__
    typedef double        CGFloat;
    typedef unsigned long NSUInteger;
    typedef signed long   NSInteger;
#else
    typedef float         CGFloat;
    typedef unsigned int  NSUInteger;
    typedef signed int    NSInteger;
#endif

typedef double NSTimeInterval;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef struct CGPoint {
    CGFloat x;
    CGFloat y;
} CGPoint, NSPoint;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef struct CGSize {
    CGFloat width;
    CGFloat height;
} CGSize, NSSize;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef struct CGRect  {
    CGPoint origin;
    CGSize size;
} CGRect, NSRect;

_oc_extern_c_begin
static inline NSRect
NSMakeRect(CGFloat x, CGFloat y, CGFloat w, CGFloat h) {
    NSRect result = { {x,y}, {w,h} };
    return result;
}
_oc_extern_c_end

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef struct NSRange {
    NSUInteger location;
    NSUInteger length;
} NSRange;

//------------------------------------------------------------------------------

oc_interface(
    NSArray,
    obj(NSUInteger, count),
    obj(id,         firstObject),
    obj(id,         lastObject),
    obj(id,         objectAtIndex,NSUInteger),
    obj(NSUInteger, indexOfObject,id),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    NSAutoreleasePool,
    cls(void, showPools),
    obj(void, drain),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    NSBundle,
    cls(NSBundle*,  mainBundle),
    obj(NSString*,  bundleIdentifier),
    obj(NSString*,  bundlePath),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    NSData,
    obj(const void*, bytes),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    NSDictionary,
    cls(NSDictionary*,
        dictionaryWithObjects,id*, 
        forKeys,NSString*,
        count,NSUInteger),
    obj(NSUInteger, count),
    obj(id,valueForKey,NSString*),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    NSCoder,
    obj(bool,           containsValueForKey,NSString*),

    obj(id,             decodeObjectForKey,NSString*),
    obj(bool,           decodeBoolForKey,NSString*),
    obj(int,            decodeIntForKey,NSString*),
    obj(int32_t,        decodeInt32ForKey,NSString*),
    obj(int64_t,        decodeInt64ForKey,NSString*),
    obj(NSInteger,      decodeIntegerForKey,NSString*),
    obj(float,          decodeFloatForKey,NSString*),
    obj(double,         decodeDoubleForKey,NSString*),
    obj(const char*,    decodeBytesForKey,NSString*,returnedLength,NSUInteger*),

    obj(void,           encodeObject,id,forKey,NSString*),
    obj(void,           encodeBool,bool,forKey,NSString*),
    obj(void,           encodeInt,int,forKey,NSString*),
    obj(void,           encodeInt32,int32_t,forKey,NSString*),
    obj(void,           encodeInt64,int64_t,forKey,NSString*),
    obj(void,           encodeInteger,NSInteger,forKey,NSString*),
    obj(void,           encodeFloat,float,forKey,NSString*),
    obj(void,           encodeDouble,double,forKey,NSString*),
    obj(void,           encodeBytes,const char*,length,NSUInteger),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    NSError,
    obj(NSUInteger, code),
    obj(NSString*,  domain),
    obj(NSString*,  localizedDescription),
    obj(NSString*,  localizedRecoveryOptions),
    obj(NSString*,  localizedRecoverySuggestion),
    obj(NSString*,  localizedFailureReason),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    NSMutableArray,
    cls(NSMutableArray*, arrayWithCapacity,NSUInteger),
    obj(void, addObject,id),
    obj(void, insertObject,id,atIndex,NSUInteger),
    obj(void, removeObjectAtIndex,NSUInteger),
    obj(void, removeLastObject),
    obj(void, replaceObjectAtIndex,NSUInteger,withObject,id)
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    NSNotification,
    obj(NSString*, name),
)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

oc_interface(
    NSString,
    cls(NSString*,   stringWithUTF8String,const char*),
    obj(const char*, UTF8String),
)

#define oc_str(CSTR) (oc_cls(NSString,stringWithUTF8String,CSTR))

#define oc_cstr(NSSTR) (oc_obj(NSSTR,NSString,UTF8String))

//------------------------------------------------------------------------------
