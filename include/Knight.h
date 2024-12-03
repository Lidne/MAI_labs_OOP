#pragma once

#include <string>
#include "BattleVisitor.h"
#include "NPC.h"

class Knight : public NPC {
  public:
   Knight(const std::string& name, int x, int y);
   std::string getType() const override;
   bool fight(NPC& other) override;
   void accept(BattleVisitor& visitor);
};
