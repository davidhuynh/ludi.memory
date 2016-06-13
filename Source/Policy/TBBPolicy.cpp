/*!
 *  \file 	TBBPolicy.cpp
 *  \brief 	<description> 
 *  \date	2011-11-3 18:04
 *
 *  Created by David Huynh on 2011/11/03.
 *  Copyright (C) 2011 David Huynh, Inc. All Rights Reserved.
 *  
 */

#include "TBBPolicy.h"

using namespace ludi::memory;

//
TBBPolicy::TBBPolicy() {

}

//
TBBPolicy::~TBBPolicy() {

}

//
void TBBPolicy::Initialize(void *memory, size_t size, size_t alignment) {

}

//
void TBBPolicy::Shutdown() {

}


void* TBBPolicy::Allocate(size_t size, size_t alignment /*= 0*/) {
    return nullptr;
    //return scalable_malloc(size);
}

//
void TBBPolicy::Deallocate(void* p, size_t size /*= 0*/) {
    //scalable_free(p);
}

//
size_t TBBPolicy::GetMaxAllocationSize() {
    //TODO
    return 0;
}


