/*
 *  Copyright (c) 2016 David Huynh
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */


#include "Memory.h"
#include "TLSFHeapPolicy.h"

namespace ludi { 
namespace memory {
	TLSFHeapPolicy::TLSFHeapPolicy() 
    {
  
    }

    TLSFHeapPolicy::~TLSFHeapPolicy()
    {

    }
    
    void TLSFHeapPolicy::Initialize(void *memory, size_t size, size_t alignment) {
        uint32 first_level;
        uint32 second_level;
        BlockHeader* block;
        tlsf_t *tlsf;

        if(BLOCK_ROUNDUP(sizeof(tlsf_t)) + MIN_BLOCK_SIZE > size) {
        return NULL;
        }

        tlsf = addr;
        memory_ = memory; 
        size_ = size;

        size = size - BLOCK_OVERHEAD;
        tlsf_mapping_insert(size, &first_level, &second_level);

        block = BUFFER_TO_BLOCK_HEADER(addr);

        block->size = size | TLSF_BLOCK_HEADER_PREV_USED;
        block->prev_free = NULL;
        block->next_free = NULL;

        first_level_bitmap_ = 1 << first_level;
        second_level_bitmaps_[first_level] = 1 << second_level;
        lists[_first_level][second_level] = block;
    }
    
    void Shutdown();

	public:
		/*! */
		void* Allocate(size_t size, size_t alignment = 0);
		/*! */
		void Deallocate(void* p, size_t size = 0);
		/*! */
		size_t GetMaxAllocationSize();
	
    public:
        
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

#endif	// LUDI_MEMORY_TLSF_HEAP_POLICY_H_
