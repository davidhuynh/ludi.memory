/*!
 *  \file 	ZeroStorage.h
 *  \brief 	<description> 
 *  \date	2011-11-3 16:11
 *
 *  Created by David Huynh on 2011/11/03.
 *  Copyright (C) 2011 David Huynh, Inc. All Rights Reserved.
 *  
 */

#ifndef LUDI_MEMORY_ZERO_STORAGE_H_
#define LUDI_MEMORY_ZERO_STORAGE_H_

#include "Memory.h"

namespace ludi { 
namespace memory {
    /*! Standard allocation using std::malloc(). */
    class Storage { 
    public:
        /*! */
        virtual void* Create(size_t size, size_t alignment) =0;

        /*! */
        virtual Destroy() = 0;
    };

} // memory	
} // ludi

#endif // LUDI_MEMORY_ZERO_STORAGE_H_
