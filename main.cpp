#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <random>
#include <string>
#include <vector>
#include "BattleVisitor.h"
#include "ConsoleLogger.h"
#include "FileLogger.h"
#include "NPC.h"
#include "NPCFactory.h"

int main() {
   std::vector<std::shared_ptr<NPC>> npcs;

   auto consoleLogger = std::make_shared<ConsoleLogger>();
   auto fileLogger = std::make_shared<FileLogger>();

   npcs.push_back(NPCFactory::createNPC("Knight", "Arthur", 50, 50));
   npcs.push_back(NPCFactory::createNPC("Elf", "Legolas", 100, 100));
   npcs.push_back(NPCFactory::createNPC("Druid", "Merlin", 200, 200));

   for (const auto& npc : npcs) {
      std::cout << npc->getName() << " (" << npc->getType() << ") at ("
                << npc->getX() << ", " << npc->getY() << ")" << std::endl;
   }

   BattleVisitor battle(150.0, npcs);
   battle.addObserver(consoleLogger);
   battle.addObserver(fileLogger);

   return 0;
}
