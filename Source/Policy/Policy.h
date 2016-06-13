/*!
 *  \file 	TbbMemoryPolicy.h
 *  \brief 	<description> 
 *  \date	2011-11-3 16:05
 *
 *  Created by David Huynh on 2011/11/03.
 *  Copyright (C) 2011 David Huynh, Inc. All Rights Reserved.
 *  
 */

#ifndef LUDI_MEMORY_POLICY_H_
#define LUDI_MEMORY_POLICY_H_

#include "Memory.h"

namespace ludi { 
namespace memory {
	/*! */
	class Policy { 
	public:
		/*! */
		virtual void Initialize(void *memory, size_t size, size_t alignment) = 0;
		/*! */
		virtual void Shutdown() = 0;

	public:
		/*! */
		virtual void* Allocate(size_t size, size_t alignment = 0) = 0;
		/*! */
		virtual void Deallocate(void* p, size_t size = 0) = 0;
		/*! */
		virtual size_t GetMaxAllocationSize() = 0;		
	};

} // memory	
} // ludi

#endif	// LUDI_MEMORY_TBB_POLICY_H_

