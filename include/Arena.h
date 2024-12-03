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
   void registerNPC(std::unique_ptr<NPC> character);
   void subscribeObserver(std::shared_ptr<Observer> listener);
   void initiateCombat(double attackRadius);
   void createNPC(const std::string &npcType, const std::string &npcName,
                  int posX, int posY);
   void exportNPCs(const std::string &outputFile);
   void importNPCs(const std::string &inputFile);
   void displayNPCs() const;

  private:
   int arenaWidth, arenaHeight;
   std::vector<std::shared_ptr<NPC>> characterList;
   std::vector<std::shared_ptr<Observer>> observerList;

   int generateRandomCoordinate(int lowerBound, int upperBound);
};