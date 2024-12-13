#include "Arena.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include "BattleVisitor.h"

Arena::Arena(int arenaWidth, int arenaHeight)
    : arenaWidth(arenaWidth), arenaHeight(arenaHeight) {}

void Arena::registerNPC(std::shared_ptr<NPC> character) {
   characterList.push_back(std::move(character));
}

void Arena::subscribeObserver(std::shared_ptr<Observer> listener) {
   observerList.push_back(listener);
}

void Arena::initiateCombat(double attackRadius) {
   std::cout << "Initiating combat with radius: " << attackRadius << std::endl;

   for (auto &listener : observerList) {
      listener->notify("Combat started with radius: " +
                       std::to_string(attackRadius));
   }

   BattleVisitor battleHandler(attackRadius, characterList, observerList);
   std::vector<NPC *> activeCharacters;
   for (auto &character : characterList) {
      activeCharacters.push_back(character.get());
   }

   for (auto npcIt = activeCharacters.begin();
        npcIt != activeCharacters.end();) {
      NPC *character = *npcIt;

      auto found =
          std::find_if(characterList.begin(), characterList.end(),
                       [character](const std::unique_ptr<NPC> &original) {
                          return original.get() == character;
                       });

      if (found != characterList.end()) {
         character->accept(battleHandler);
      }

      ++npcIt;
   }

   if (characterList.empty()) {
      for (auto &listener : observerList) {
         listener->notify("All NPCs defeated. Combat ended.");
      }
   } else {
      std::string survivorsReport = "Combat ended. Surviving NPCs: ";
      for (const auto &character : characterList) {
         survivorsReport += character->getName() + " ";
      }
      for (auto &listener : observerList) {
         listener->notify(survivorsReport);
      }
   }
}

void Arena::createNPC(const std::string &npcType, const std::string &npcName,
                      int posX, int posY) {
   if (posX == -1 || posY == -1) {
      posX = generateRandomCoordinate(0, arenaWidth);
      posY = generateRandomCoordinate(0, arenaHeight);
   }

   auto character = NPCFactory::createNPC(npcType, npcName, posX, posY);
   if (character) {
      registerNPC(std::move(character));
   } else {
      std::cerr << "Error creating NPC of type: " << npcType << "\n";
   }
}

int Arena::generateRandomCoordinate(int lowerBound, int upperBound) {
   static std::random_device rd;
   static std::mt19937 gen(rd());
   std::uniform_int_distribution<> dis(lowerBound, upperBound);
   return dis(gen);
}

void Arena::exportNPCs(const std::string &outputFile) {
   std::ofstream file(outputFile);
   if (!file.is_open()) {
      throw std::runtime_error("Failed to open file for exporting NPCs");
   }
   for (const auto &character : characterList) {
      file << character->getName() << " " << character->getX() << " "
           << character->getY() << " " << character->getType() << "\n";
   }
   file.close();
}

void Arena::displayNPCs() const {
   for (const auto &character : characterList) {
      std::cout << "Type: " << character->getType()
                << ", Name: " << character->getName() << ", Coordinates: ("
                << character->getX() << ", " << character->getY() << ")\n";
   }
}