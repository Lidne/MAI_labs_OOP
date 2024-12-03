#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <random>
#include <string>
#include <vector>

class NPCFactory {
  public:
   static std::shared_ptr<NPC> createNPC(const std::string& type,
                                         const std::string& name, int x,
                                         int y) {
      if (type == "Knight") return std::make_shared<Knight>(name, x, y);
      if (type == "Elf") return std::make_shared<Elf>(name, x, y);
      if (type == "Druid") return std::make_shared<Druid>(name, x, y);
      throw std::invalid_argument("Invalid NPC type");
   }
};