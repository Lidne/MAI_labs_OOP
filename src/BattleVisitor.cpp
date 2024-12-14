#include "BattleVisitor.h"
#include <memory>
#include <shared_mutex>
#include <string>
#include <vector>
#include "NPC.h"

BattleVisitor::BattleVisitor(std::vector<std::shared_ptr<NPC>>& npcs,
                             std::vector<std::shared_ptr<Observer>>& observers)
    : Visitor(npcs, observers) {}

void BattleVisitor::visit(std::unique_ptr<NPC> npc) {
   for (size_t i = 0; i < npcs.size(); ++i) {
      auto enemy = *npcs[i];
      if (npc->isInRange(enemy)) {
         if (!npc || !enemy.isAlive()) return;

         int attack1 = dice();
         int defense2 = dice();

         if (attack1 > defense2) {
            enemy.setAlive(false);
            return;
         }

         int attack2 = dice();
         int defense1 = dice();

         if (attack2 > defense1) {
            npc->setAlive(false);
         }
      }
   }
}
// void BattleVisitor::visit(Knight& knight) {
//    for (size_t i = 0; i < npcs.size(); ++i) {
//       if (npcs[i]->distanceTo(knight) <= fightDistance) {
//          auto npc1 = npcs[i];
//          bool npc1Survives = npc1->fight(knight);
//          bool npc2Survives = knight.fight(*npc1);

//          if (!npc1Survives || !npc2Survives) {
//             std::string event = npc1->getName() + " (" + npc1->getType() +
//                                 ") fought " + knight.getName() + " (" +
//                                 knight.getType() + ")";
//             notifyObservers(event);

//             if (!npc1Survives) {
//                notifyObservers(npc1->getName() + " died.");
//                npcs.erase(npcs.begin() + i);
//                --i;
//                break;
//             }
//          }
//       }
//    }
// }

// void BattleVisitor::visit(Elf& elf) {
//    for (size_t i = 0; i < npcs.size(); ++i) {
//       if (npcs[i]->distanceTo(elf) <= fightDistance) {
//          auto npc1 = npcs[i];
//          bool npc1Survives = npc1->fight(elf);
//          bool npc2Survives = elf.fight(*npc1);

//          if (!npc1Survives || !npc2Survives) {
//             std::string event = npc1->getName() + " (" + npc1->getType() +
//                                 ") fought " + elf.getName() + " (" +
//                                 elf.getType() + ")";
//             notifyObservers(event);

//             if (!npc1Survives) {
//                notifyObservers(npc1->getName() + " died.");
//                npcs.erase(npcs.begin() + i);
//                --i;
//                break;
//             }
//          }
//       }
//    }
// }
// void BattleVisitor::visit(Druid& druid) {
//    for (size_t i = 0; i < npcs.size(); ++i) {
//       if (npcs[i]->distanceTo(druid) <= fightDistance) {
//          auto npc1 = npcs[i];
//          bool npc1Survives = npc1->fight(druid);
//          bool npc2Survives = druid.fight(*npc1);

//          if (!npc1Survives || !npc2Survives) {
//             std::string event = npc1->getName() + " (" + npc1->getType() +
//                                 ") fought " + druid.getName() + " (" +
//                                 druid.getType() + ")";
//             notifyObservers(event);

//             if (!npc1Survives) {
//                notifyObservers(npc1->getName() + " died.");
//                npcs.erase(npcs.begin() + i);
//                --i;
//                break;
//             }
//          }
//       }
//    }
// }
