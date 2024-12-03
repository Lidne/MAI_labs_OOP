#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <random>
#include <string>
#include <vector>

class Elf : public NPC {
  public:
   Elf(const std::string& name, int x, int y) : NPC(name, x, y) {}
   std::string getType() const override { return "Elf"; }

   bool fight(NPC& other) override {
      return false;  // Убивает всех, но сам погибает.
   }

   void accept(BattleVisitor& visitor) override;
};

void Elf::accept(BattleVisitor& visitor) { visitor.visit(*this); }
