//
//  NSObject+DWAssociatedObjects.m
//  DWObjCRuntimeKit
//
//  Created by Sven Song on 4/25/17.
//  Copyright © 2017 dreamingwish.com All rights reserved.
//

@import ObjectiveC;
#import "NSObject+DWAssociatedObjects.h"

@implementation NSObject (DWAssociatedObjects)

- (id)dw_getAssociatedObjectForKey:(NSString *)key
{
    const void * k = (const void *)key.hash;
    return objc_getAssociatedObject(self, k);
}

- (void)dw_assignAssociatedObject:(id)obj forKey:(NSString *)key
{
    const void * k = (const void *)key.hash;
    objc_setAssociatedObject(self, k, obj, OBJC_ASSOCIATION_ASSIGN);
}

- (void)dw_setAssociatedObject:(id)obj forKey:(NSString *)key
{
    const void * k = (const void *)key.hash;
    objc_setAssociatedObject(self, k, obj, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (void)dw_setCopyAssociatedObject:(id)obj forKey:(NSString *)key
{
    const void * k = (const void *)key.hash;
    objc_setAssociatedObject(self, k, obj, OBJC_ASSOCIATION_COPY_NONATOMIC);
}

@end
