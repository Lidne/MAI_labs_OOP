#include "Druid.h"
#include <string>

Druid::Druid(const std::string& name, int x, int y) : NPC(name, x, y) {}

std::string Druid::getType() const { return "Druid"; }

bool Druid::fight(NPC& other) {
   return true;  // канибализм)
}

void Druid::accept(BattleVisitor& visitor) { visitor.visit(*this); }
