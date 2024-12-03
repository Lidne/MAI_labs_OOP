#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <random>
#include <string>
#include <vector>

class FileLogger : public Observer {
   std::ofstream logFile;

  public:
   FileLogger() { logFile.open("log.txt", std::ios::app); }
   void notify(const std::string& event) override {
      if (logFile.is_open()) {
         logFile << event << std::endl;
      }
   }
   ~FileLogger() {
      if (logFile.is_open()) {
         logFile.close();
      }
   }
};