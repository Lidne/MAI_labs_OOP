#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <random>
#include <string>
#include <vector>

class Knight : public NPC {
  public:
   Knight(const std::string& name, int x, int y) : NPC(name, x, y) {}
   std::string getType() const override { return "Knight"; }

   bool fight(NPC& other) override {
      return other.getType() != "Elf";  // Убивает только Эльф.
   }

   void accept(BattleVisitor& visitor) override;
};

void Knight::accept(BattleVisitor& visitor) { visitor.visit(*this); }
