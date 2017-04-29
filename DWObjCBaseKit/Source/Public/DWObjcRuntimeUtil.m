//
//  DWObjCRuntimeUtil.m
//  DWObjCRuntimeKit
//
//  Created by Sven Song on 4/25/17.
//  Copyright © 2017 dreamingwish.com All rights reserved.
//

#import "DWObjCRuntimeUtil.h"

const void *DWBlockGetInvokeFunction(id block)
{
    const void *identifier = NULL;

    //The pointer of a block itself is not stable and unique(stack block may be copied onto heap), we should use the block's invoke function pointer. The invoke function can take different parameters, but blocks are immutable, so using the invoke function pointer is enough for building identifiers.
    //The memory layout of blocks are like this: https://clang.llvm.org/docs/Block-ABI-Apple.html#high-level
    struct Block_literal_1 {
        void *isa;
        int flags;
        int reserved;
        void (*invoke)(void *, ...);
    };
    //1. This isn't private api call; 2. the memeory layout is stable.
    identifier = block ? ((__bridge struct Block_literal_1*)block)->invoke : NULL;
    return identifier;
}

#if __has_feature(objc_arc)
const void *DWBlockGetIdentifier(id block)
{
    //1. Under ARC: There's no chance to get a stack block, stack blocks are copied to heap immediately after definition.
    //2. Copying a __NSMallocBlock__ is actually doing a Block_Retain().
    //3. http://llvm.org/svn/llvm-project/compiler-rt/trunk/lib/BlocksRuntime/runtime.c
    //TODO: support non-arc
    return (__bridge const void *)block;
}
#endif
