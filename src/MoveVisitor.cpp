#include "MoveVisitor.h"
#include <memory>
#include <shared_mutex>
#include <string>
#include <vector>
#include "NPC.h"

MoveVisitor::MoveVisitor(std::vector<std::shared_ptr<NPC>>& npcs,
                         std::vector<std::shared_ptr<Observer>>& observers,
                         int width, int height)
    : Visitor(npcs, observers), width(width), height(height) {}

void MoveVisitor::visit(std::unique_ptr<NPC> npc) {
   if (!npc->isAlive()) return;

   int x = dice(), y = dice();
   while (!(0 <= x && x <= width && 0 <= y && y <= height)) {
      x = dice();
      y = dice();
   }
   npc->move(x, y);
}
