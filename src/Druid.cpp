#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <random>
#include <string>
#include <vector>

class Druid : public NPC {
  public:
   Druid(const std::string& name, int x, int y) : NPC(name, x, y) {}
   std::string getType() const override { return "Druid"; }

   bool fight(NPC& other) override {
      return true;  // канибализм)
   }

   void accept(BattleVisitor& visitor) override;
};

void Druid::accept(BattleVisitor& visitor) { visitor.visit(*this); }
