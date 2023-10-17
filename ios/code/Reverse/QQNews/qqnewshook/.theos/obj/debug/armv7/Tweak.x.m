#line 1 "Tweak.x"

#include <substrate.h>
#if defined(__clang__)
#if __has_feature(objc_arc)
#define _LOGOS_SELF_TYPE_NORMAL __unsafe_unretained
#define _LOGOS_SELF_TYPE_INIT __attribute__((ns_consumed))
#define _LOGOS_SELF_CONST const
#define _LOGOS_RETURN_RETAINED __attribute__((ns_returns_retained))
#else
#define _LOGOS_SELF_TYPE_NORMAL
#define _LOGOS_SELF_TYPE_INIT
#define _LOGOS_SELF_CONST
#define _LOGOS_RETURN_RETAINED
#endif
#else
#define _LOGOS_SELF_TYPE_NORMAL
#define _LOGOS_SELF_TYPE_INIT
#define _LOGOS_SELF_CONST
#define _LOGOS_RETURN_RETAINED
#endif

@class QNAdItem; 
static QNAdItem* (*_logos_orig$_ungrouped$QNAdItem$initWithInfo$)(_LOGOS_SELF_TYPE_INIT QNAdItem*, SEL, id) _LOGOS_RETURN_RETAINED; static QNAdItem* _logos_method$_ungrouped$QNAdItem$initWithInfo$(_LOGOS_SELF_TYPE_INIT QNAdItem*, SEL, id) _LOGOS_RETURN_RETAINED; 

#line 1 "Tweak.x"


static QNAdItem* _logos_method$_ungrouped$QNAdItem$initWithInfo$(_LOGOS_SELF_TYPE_INIT QNAdItem* __unused self, SEL __unused _cmd, id arg1) _LOGOS_RETURN_RETAINED {

	return nil;
}


static __attribute__((constructor)) void _logosLocalInit() {
{Class _logos_class$_ungrouped$QNAdItem = objc_getClass("QNAdItem"); MSHookMessageEx(_logos_class$_ungrouped$QNAdItem, @selector(initWithInfo:), (IMP)&_logos_method$_ungrouped$QNAdItem$initWithInfo$, (IMP*)&_logos_orig$_ungrouped$QNAdItem$initWithInfo$);} }
#line 9 "Tweak.x"
