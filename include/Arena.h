#pragma once

#include <memory>
#include <random>
#include <vector>
#include "BattleVisitor.h"
#include "NPC.h"
#include "NPCFactory.h"
#include "Observer.h"

class Arena {
  public:
   Arena(int arenaWidth, int arenaHeight);
   void registerNPC(std::shared_ptr<NPC> character);
   void subscribeObserver(std::shared_ptr<Observer> listener);
   void initiateCombat(double attackRadius);
   void displayNPCs() const;

  private:
   int arenaWidth, arenaHeight;
   std::vector<std::shared_ptr<NPC>> characterList;
   std::vector<std::shared_ptr<Observer>> observerList;

   int generateRandomCoordinate(int lowerBound, int upperBound);
};