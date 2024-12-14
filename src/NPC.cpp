#include "NPC.h"
#include <cmath>
#include <string>

NPC::NPC(const std::string& name, int x, int y, double attackRadius)
    : name(name), x(x), y(y), attackRadius(attackRadius) {}

NPC::NPC(const NPC& other)
    : name(other.name),
      x(other.x),
      y(other.y),
      attackRadius(other.attackRadius),
      moveRadius(other.moveRadius) {}

const std::string& NPC::getName() const { return name; }

int NPC::getX() const { return x; }
int NPC::getY() const { return y; }

double NPC::distanceTo(const NPC& other) const {
   return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
}

bool NPC::isInRange(const NPC& other) const {
   return attackRadius >= distanceTo(other);
}

bool NPC::isAlive() const { return alive; }

void NPC::setAlive(bool state) { alive = state; }

void NPC::move(int dirX, int dirY) {
   x += dirX * int(moveRadius);
   y += dirY * int(moveRadius);
}

bool NPC::inBorders(int width, int height) const {
   return 0 <= x && x <= width && 0 <= y && y <= height;
}
