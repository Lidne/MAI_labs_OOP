#include <iostream>
#include <iterator>
#include <memory_resource>
#include "MemoryResource.h"

MemoryResource::~MemoryResource() {
   for (void* ptr : allocated_blocks) {
      ::operator delete(ptr);
   }
}

void* MemoryResource::do_allocate(std::size_t bytes, std::size_t alignment) {
   void* ptr = ::operator new(bytes, std::align_val_t(alignment));
   allocated_blocks.push_back(ptr);
   return ptr;
}

void MemoryResource::do_deallocate(void* ptr, std::size_t bytes,
                                   std::size_t alignment) {
   auto it = std::find(allocated_blocks.begin(), allocated_blocks.end(), ptr);
   if (it != allocated_blocks.end()) {
      allocated_blocks.erase(it);
      ::operator delete(ptr, std::align_val_t(alignment));
   }
}

bool MemoryResource::do_is_equal(
    const std::pmr::memory_resource& other) const noexcept {
   return this == &other;
}
