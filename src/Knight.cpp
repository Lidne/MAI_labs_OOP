#include "Knight.h"
#include <string>

Knight::Knight(const std::string& name, int x, int y) : NPC(name, x, y) {}

std::string Knight::getType() const { return "Knight"; }

bool Knight::fight(NPC& other) { return other.getType() != "Elf"; }

void Knight::accept(BattleVisitor& visitor) { visitor.visit(*this); }
