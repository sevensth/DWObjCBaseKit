//
//  DWTypeDefine.h
//  DWObjCRuntimeKit
//
//  Created by Sven Song on 4/29/17.
//  Copyright © 2017 dreamingwish.com All rights reserved.
//

@import Foundation;

#define DWLog(...)

NS_ASSUME_NONNULL_BEGIN

typedef void (^DWVoidBlock)(void);
typedef void (^DWBoolBlock)(BOOL finished);
/**
 * Using __kindof allows replacing NSObject* to any specified type for an observer, like ^(BBDemoViewController * _Nonnull observer, NSDictionary<NSString *, id> * _Nullable change).
 */
typedef void (^DWKVOCallbackBlock)(__kindof NSObject* observer, NSDictionary<NSString *, id> * _Nullable change);

NS_ASSUME_NONNULL_END
