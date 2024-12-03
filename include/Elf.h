#pragma once

#include <string>
#include "BattleVisitor.h"
#include "NPC.h"

class Elf : public NPC {
  public:
   Elf(const std::string& name, int x, int y);
   std::string getType() const override;
   bool fight(NPC& other) override;
   void accept(BattleVisitor& visitor);
};
