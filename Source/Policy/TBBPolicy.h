/*!
 *  \file 	TbbMemoryPolicy.h
 *  \brief 	<description> 
 *  \date	2011-11-3 16:05
 *
 *  Created by David Huynh on 2011/11/03.
 *  Copyright (C) 2011 David Huynh, Inc. All Rights Reserved.
 *  
 */

#ifndef LUDI_MEMORY_TBB_POLICY_H_
#define LUDI_MEMORY_TBB_POLICY_H_

#include "Memory.h"

namespace ludi { 
namespace memory {
	/*! */
	class TBBPolicy { 
	public:
		/*! */
		TBBPolicy();
		/*! */
		~TBBPolicy();

	private:
		/*! */
		DISALLOW_COPY_AND_ASSIGN(TBBPolicy);

	public:
		/*! */
		void Initialize(void *memory, size_t size, size_t alignment);
		/*! */
		void Shutdown();

	public:
		/*! */
		void* Allocate(size_t size, size_t alignment = 0);
		/*! */
		void Deallocate(void* p, size_t size = 0);
		/*! */
		size_t GetMaxAllocationSize();
		
	public:
		/*! <dwmstl::memory::TLSFHeapPolicy::initialized>
		 *  @return bool */
		bool initialized() const { return true; }
		/*! Indicates whether or not it needs to preallocate memory from storage 
		 *	to create objects.
		 *  @return bool True, if the policy needs preallocate memory. False, otherwise. */
		bool demand() const { return false; }
	};

}	// memory	
}	// ludi

#endif	// LUDI_MEMORY_TBB_POLICY_H_

