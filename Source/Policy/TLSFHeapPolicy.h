/*
 *  Copyright (c) 2018 David Huynh
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


#ifndef LUDI_MEMORY_TLSF_HEAP_POLICY_H_
#define LUDI_MEMORY_TLSF_HEAP_POLICY_H_

//#include "Memory.h"

namespace ludi { 
namespace memory {
	/*! 
     *  \reference https://github.com/missimer/tlsf */
	class TLSFHeapPolicy : boost::noncopyable { 
	public:
        /*! */
        struct BlockHeader {
            BlockHeader* previous_physical;

            union {
                size_t size;
                struct {
                    unsigned int used : 1;
                    unsigned int prev_used : 1;
                    unsigned int unused : 30;
                };
            };
            
            #ifdef TLSF_MEMORY_TAGS
            size_t tag;
            #endif // TLSF_MEMORY_TAGS
            
            #ifdef TLSF_RED_ZONES
            size_t requested_size;
            #endif // TLSF_RED_ZONES

            BlockHeader* next_free;
            BlockHeader* previous_free;
        } __attribute__ ((packed));
        
	public:
		/*! */
		TLSFHeapPolicy();
		/*! */
		~TLSFHeapPolicy();

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

