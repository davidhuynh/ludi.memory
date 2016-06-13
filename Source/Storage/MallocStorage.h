/*!
 *  \file 	MallocStorage.h
 *  \brief 	<description> 
 *  \date	2011-11-3 14:29
 *
 *  Created by David Huynh on 2011/11/03.
 *  Copyright (C) 2011 David Huynh, Inc. All Rights Reserved.
 *  
 */

#ifndef LUDI_MEMORY_MALLOC_STORAGE_H_
#define LUDI_MEMORY_MALLOC_STORAGE_H_

#include "Memory.h"

namespace ludi { 
namespace memory {
	/*! Standard allocation using std::malloc(). */
	class MallocStorage { 
	protected:
		void* memory_;		//!<
		size_t size_;		//!<
		size_t alignment_;	//!<

	public:
		/*! */
		MallocStorage();
		/*! */
		virtual ~MallocStorage();

	private:
		DISALLOW_COPY_AND_ASSIGN(MallocStorage);

	public:
		/*! */
		void* Create(size_t size, size_t alignment);
		/*! */
		void Destroy();
	};

}	// memory	
}	// ludi

#endif	// LUDI_MEMORY_MALLOC_STORAGE_H_
