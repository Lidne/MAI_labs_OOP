#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <random>
#include <string>
#include <vector>

class NPC {
  protected:
   std::string name;
   int x, y;

  public:
   NPC(const std::string& name, int x, int y) : name(name), x(x), y(y) {}
   virtual ~NPC() = default;

   virtual std::string getType() const = 0;

   const std::string& getName() const { return name; }
   int getX() const { return x; }
   int getY() const { return y; }

   double distanceTo(const NPC& other) const {
      return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
   }

   virtual bool fight(
       NPC& other) = 0;  // Возвращает true, если текущий NPC выжил
   virtual void accept(BattleVisitor& visitor) = 0;
};