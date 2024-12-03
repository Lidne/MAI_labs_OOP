#include "BattleVisitor.h"
#include <string>
#include <vector>

BattleVisitor::BattleVisitor(double distance,
                             std::vector<std::shared_ptr<NPC>>& npcs,
                             std::vector<std::shared_ptr<Observer>> observers)
    : fightDistance(distance), npcs(npcs), observers(observers) {}

void BattleVisitor::addObserver(std::shared_ptr<Observer> observer) {
   observers.push_back(observer);
}

void BattleVisitor::notifyObservers(const std::string& event) {
   for (const auto& observer : observers) {
      observer->notify(event);
   }
}

void BattleVisitor::visit(Knight& knight) {
   for (size_t i = 0; i < npcs.size(); ++i) {
      if (npcs[i]->distanceTo(knight) <= fightDistance) {
         auto npc1 = npcs[i];
         bool npc1Survives = npc1->fight(knight);
         bool npc2Survives = knight.fight(*npc1);

         if (!npc1Survives || !npc2Survives) {
            std::string event = npc1->getName() + " (" + npc1->getType() +
                                ") fought " + knight.getName() + " (" +
                                knight.getType() + ")";
            notifyObservers(event);

            if (!npc1Survives) {
               notifyObservers(npc1->getName() + " died.");
               npcs.erase(npcs.begin() + i);
               --i;
               break;
            }
         }
      }
   }
}

void BattleVisitor::visit(Elf& elf) {
   for (size_t i = 0; i < npcs.size(); ++i) {
      if (npcs[i]->distanceTo(elf) <= fightDistance) {
         auto npc1 = npcs[i];
         bool npc1Survives = npc1->fight(elf);
         bool npc2Survives = elf.fight(*npc1);

         if (!npc1Survives || !npc2Survives) {
            std::string event = npc1->getName() + " (" + npc1->getType() +
                                ") fought " + elf.getName() + " (" +
                                elf.getType() + ")";
            notifyObservers(event);

            if (!npc1Survives) {
               notifyObservers(npc1->getName() + " died.");
               npcs.erase(npcs.begin() + i);
               --i;
               break;
            }
         }
      }
   }
}
void BattleVisitor::visit(Druid& druid) {
   for (size_t i = 0; i < npcs.size(); ++i) {
      if (npcs[i]->distanceTo(druid) <= fightDistance) {
         auto npc1 = npcs[i];
         bool npc1Survives = npc1->fight(druid);
         bool npc2Survives = druid.fight(*npc1);

         if (!npc1Survives || !npc2Survives) {
            std::string event = npc1->getName() + " (" + npc1->getType() +
                                ") fought " + druid.getName() + " (" +
                                druid.getType() + ")";
            notifyObservers(event);

            if (!npc1Survives) {
               notifyObservers(npc1->getName() + " died.");
               npcs.erase(npcs.begin() + i);
               --i;
               break;
            }
         }
      }
   }
}
