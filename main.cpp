#include <iostream>
#include "./src/DynamicArray.cpp"
#include "./src/MemoryResource.cpp"

using namespace std;

struct ComplexType {
   int id;
   std::string name;
};

int main() {
   MemoryResource custom_resource;
   DynamicArray<int> int_array(&custom_resource);
   int_array.push_back(1);
   int_array.push_back(2);
   int_array.push_back(3);

   std::cout << "Integer array contents: ";
   for (auto& val : int_array) {
      std::cout << val << " ";
   }
   std::cout << std::endl;

   DynamicArray<ComplexType> complex_array(&custom_resource);
   complex_array.push_back({1, "Alice"});
   complex_array.push_back({2, "Bob"});

   std::cout << "ComplexType array contents: ";
   for (auto& val : complex_array) {
      std::cout << "{ id: " << val.id << ", name: " << val.name << " } ";
   }
   std::cout << std::endl;

   return 0;
}