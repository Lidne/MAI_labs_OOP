#pragma once

#include <string>
#include "BattleVisitor.h"
#include "NPC.h"

class Druid : public NPC {
  public:
   Druid(const std::string& name, int x, int y);
   std::string getType() const override;
   bool fight(NPC& other) override;
   void accept(BattleVisitor& visitor);
};
