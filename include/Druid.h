#pragma once

#include <string>
#include "Visitor.h"
#include "NPC.h"

class Druid : public NPC {
   const double ATTACK_RADIUS = 10.0;
   const double MOVE_RADIUS = 10.0;

  public:
   Druid(const std::string& name, int x, int y);
   std::string getType() const override;
   void accept(Visitor& visitor);
};
