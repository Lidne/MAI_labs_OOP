#pragma once

#include <string>
#include "BattleVisitor.h"

class NPC {
  protected:
   std::string name;
   int x, y;

  public:
   NPC(const std::string& name, int x, int y);
   virtual ~NPC() = default;
   virtual std::string getType() const = 0;
   const std::string& getName() const;
   int getX() const;
   int getY() const;
   double distanceTo(const NPC& other) const;
   virtual bool fight(NPC& other) = 0;
   virtual void accept(BattleVisitor& visitor) = 0;
};