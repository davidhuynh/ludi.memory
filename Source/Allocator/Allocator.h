/*
 *  Allocator.h
 *
 *  Created by David Huynh on 6/13/2011.
 *  Copyright 2011 David Huynh Inc. All Rights Reserved.
 *
 */

#ifndef LUDI_MEMORY_ALLOCATOR_H_
#define LUDI_MEMORY_ALLOCATOR_H_

#include "Memory.h"

namespace ludi { 
namespace memory {
	/*! */
	template <typename Storage, typename Policy>	// TODO add alignment template?
	class Allocator : public Policy {
    public:
        /*! */
        struct Config {
        public:
            // TODO
            //Storage::Config storage_config;
            //Policy::Config policy_config;
        };
        
	protected:
		Storage storage_;		//!<

	public:
		/*! */
		virtual ~Allocator() {
			Destroy();
		}

	public:
		/*! */
		void Create(size_t size, size_t alignment) {
			//assert(bytes && alignment);

			Destroy();

			void* memory = NULL;

			if (Policy::demand()) {
				memory= storage_.Create(size, alignment);
			}

			if (memory || !Policy::demand()) {
				Policy::Initialize(memory, size, alignment);
			}
			
		}

		/*! */
		void Destroy() {
			if (Policy::initialized()) {
				Policy::Shutdown();

				if (Policy::demand()) {					
					storage_.Destroy();
				} 
			}
		}

	public:
		/*! */
		virtual void* Allocate(size_t size, int flags = 0) {
			// TODO debug stuff here
			return Policy::Allocate(size);
		}

        /*! */
		virtual void* Allocate(size_t size, const char* pName, int flags, unsigned debugFlags, const char* file, int line) {
			// TODO debug stuff here
			return Policy::Allocate(size);
		}

		/*! */
		virtual void* Allocate(size_t size, size_t alignment, size_t alignmentOffset, const char* pName, int flags, unsigned debugFlags, const char* file, int line) {
			// TODO debug stuff here
			return Policy::Allocate(size, alignment);
		}

        /*! */
		virtual void Deallocate(void* p, size_t size = 0) {
			// TODO debug stuff here
			return Policy::Deallocate(p, size);
		}

		/*! */
		virtual size_t GetMaxAllocationSize() {
			return Policy::GetMaxAllocationSize();
		}

	};

}	// memory	
}	// ludi

#endif	// LUDI_MEMORY_ALLOCATOR_H_
