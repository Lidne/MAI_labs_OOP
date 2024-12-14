#pragma once

#include <string>
#include "NPC.h"
#include "Visitor.h"

class Elf : public NPC {
   const double ATTACK_RADIUS = 50.0;
   const double MOVE_RADIUS = 10.0;

  public:
   Elf(const std::string& name, int x, int y);
   std::string getType() const override;
   void accept(Visitor& visitor);
};
