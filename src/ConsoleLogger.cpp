#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <random>
#include <string>
#include <vector>

class ConsoleLogger : public Observer {
  public:
   void notify(const std::string& event) override {
      std::cout << event << std::endl;
   }
};