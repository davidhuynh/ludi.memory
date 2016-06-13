#ifndef LUDI_MEMORY_HEAP_POLICY_H_
#define LUDI_MEMORY_HEAP_POLICY_H_

#include "Memory.h"

namespace ludi { 
namespace memory {
	/*! */
	class HeapPolicy { 
	public:
		/*! */
		HeapPolicy();
		/*! */
		~HeapPolicy();

	private:
		/*! */
		//DISALLOW_COPY_AND_ASSIGN(HeapPolicy);

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

#endif	// LUDI_MEMORY_HEAP_POLICY_H_

