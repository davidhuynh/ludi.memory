#include "Memory.h"
#include "HeapPolicy.h"

namespace ludi {
namespace memory {
    
    //
    HeapPolicy::HeapPolicy() {

    }

    //
    HeapPolicy::~HeapPolicy() {

    }

    //
    void HeapPolicy::Initialize(void *memory, size_t size, size_t alignment) {

    }

    //
    void HeapPolicy::Shutdown() {

    }

    void* HeapPolicy::Allocate(size_t size, size_t alignment /*= 0*/) {
        return nullptr;
        //return scalable_malloc(size);
    }

    //
    void HeapPolicy::Deallocate(void* p, size_t size /*= 0*/) {
        //scalable_free(p);
    }

    //
    size_t HeapPolicy::GetMaxAllocationSize() {
        //TODO
        return 0;
    }

} // memory
} // ludi
