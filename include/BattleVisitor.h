#pragma once

#include <memory>
#include <string>
#include <vector>
#include "Druid.h"
#include "Elf.h"
#include "Knight.h"
#include "NPC.h"
#include "Observer.h"

class BattleVisitor {
   std::vector<std::shared_ptr<NPC>>& npcs;
   double fightDistance;
   std::vector<std::shared_ptr<Observer>> observers;

  public:
   BattleVisitor(double distance, std::vector<std::shared_ptr<NPC>>& npcs,
                 std::vector<std::shared_ptr<Observer>>& observers);
   void addObserver(std::shared_ptr<Observer> observer);
   void notifyObservers(const std::string& event);
   void visit(Knight& knight);
   void visit(Elf& elf);
   void visit(Druid& druid);
};