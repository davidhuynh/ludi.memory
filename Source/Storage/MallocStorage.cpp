/*
 *  MallocStorage.h
 *
 *  Created by David Huynh on 7/20/2011.
 *  Copyright 2011 David Huynh Inc. All Rights Reserved.
 *
 */

#include "MallocStorage.h"

using namespace ludi::memory;

//
MallocStorage::MallocStorage() 
    : memory_(nullptr)
    , size_(0)
{ 
    // nothing
}

// 
MallocStorage::~MallocStorage() { 
    Destroy();
}

//
void* MallocStorage::Create(size_t size, size_t alignment) {
    if (memory_) { return memory_; }

    size_ = size;
    alignment_ = alignment;
    
    // TODO
    /*if (alignment) {
        memory_ = _aligned_malloc(size, alignment);
    } else {
        memory_ = malloc(size);
    }*/

    return memory_;
}

//
void MallocStorage::Destroy() {
    if (memory_) {
        // TODO
        /*if (alignment_) {
            _aligned_free(memory_);
        } else { 
            free(memory_);
        }*/

        memory_ = nullptr;
        size_ = 0;
        alignment_ = 0;
    }
}
