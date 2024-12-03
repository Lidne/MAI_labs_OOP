#include "Elf.h"
#include <string>

Elf::Elf(const std::string& name, int x, int y) : NPC(name, x, y) {}

std::string Elf::getType() const { return "Elf"; }

bool Elf::fight(NPC& other) { return false; }

void Elf::accept(BattleVisitor& visitor) { visitor.visit(*this); }
