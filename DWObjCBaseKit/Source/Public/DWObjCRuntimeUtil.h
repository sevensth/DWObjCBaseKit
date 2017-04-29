//
//  DWObjCRuntimeUtil.h
//  DWObjCRuntimeKit
//
//  Created by Sven Song on 4/25/17.
//  Copyright © 2017 dreamingwish.com All rights reserved.
//

@import ObjectiveC;
@import Foundation;

/**
 * Hooks an instance method of a class.
 * @param cls The class that respons to the given selector.
 * @param select The select you want to hook.
 * @param block The block that will be called when the hooked method being called. It should be defined inline if you want to call origin IMP. Its signature should
 *  be: method_return_type ^(__unsafe_unretained id this, method_args...). The selector is not available as a parameter to this block. The __unsafe_unretained mark is necessary if you don't want the runtime to retain the 'self' before calling the block, so as any other method args of object type.
 * For example:
 * @code
 * //Hooking a method like this:
 * -(NSUInteger)[DemoClass lengthOfString:(NSString *)str]
 * //Will be write as:
 * DWClassHookInstanceMethod(DemoClass, @selector(lengthOfString:), ^NSUInteger(__unsafe_unretained id this, NSString *str) {
 *     //do what you want and optionally call original at some point
 *     return DWClassHookedMethodCallOrigin(NSUInteger, _self, str);
 * }
 * @endcode
 */
#define DWClassHookInstanceMethod(class, selector, block) do {\
    SEL _dw_hkm_sel = (selector); Class _dw_hkm_cls = (class); if (!_dw_hkm_cls || !_dw_hkm_sel) break;\
    Method _dw_hkm_oriMth = class_getInstanceMethod(_dw_hkm_cls, _dw_hkm_sel); if (!_dw_hkm_oriMth) break;\
    __block IMP _dw_hkm_oriIMP = method_setImplementation(_dw_hkm_oriMth, imp_implementationWithBlock(block));\
} while(0);
///The parameters should be exactly what the hooker block takes.
#define DWClassHookedMethodCallOrigin(returnType, this, ...) ((returnType(*)(id, SEL, ...))_dw_hkm_oriIMP)((this), _dw_hkm_sel, ##__VA_ARGS__)

/**
 * A block's invoke function pointer identifies what kind of block the given block is.
 * A block definition can have multiple block instance, they share the same invoke function.
 * @note For block definitions written in different place that even have exactly the some code, they don't share their invoke functions.
 */
FOUNDATION_EXPORT const void *DWBlockGetInvokeFunction(id block);

#if __has_feature(objc_arc)
/**
 * Get the identifier of a block. The identifier is stable only under arc currently.
 */
FOUNDATION_EXPORT const void *DWBlockGetIdentifier(id block);
#endif
