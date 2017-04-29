//
//  NSObject+DWAssociatedObjects.h
//  DWObjCRuntimeKit
//
//  Created by Sven Song on 4/25/17.
//  Copyright © 2017 dreamingwish.com All rights reserved.
//

@import Foundation;

@interface NSObject (DWAssociatedObjects)

/**
 * Get an associated object.
 */
- (id)dw_getAssociatedObjectForKey:(NSString *)key;

/**
 * Set an associated object with OBJC_ASSOCIATION_ASSIGN.
 */
- (void)dw_assignAssociatedObject:(id)obj forKey:(NSString *)key;

/**
 * Set an associated object with OBJC_ASSOCIATION_RETAIN_NONATOMIC.
 */
- (void)dw_setAssociatedObject:(id)obj forKey:(NSString *)key;

/**
 * Set an associated object with OBJC_ASSOCIATION_COPY_NONATOMIC.
 */
- (void)dw_setCopyAssociatedObject:(id)obj forKey:(NSString *)key;

@end
