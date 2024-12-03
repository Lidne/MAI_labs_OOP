#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <random>
#include <string>
#include <vector>

class Observer {
  public:
   virtual void notify(const std::string& event) = 0;
   virtual ~Observer() = default;
};