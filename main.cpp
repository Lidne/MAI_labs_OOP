#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <random>
#include <string>
#include <vector>


// Реализация методов accept

// Основная программа
int main() {
   std::vector<std::shared_ptr<NPC>> npcs;

   auto consoleLogger = std::make_shared<ConsoleLogger>();
   auto fileLogger = std::make_shared<FileLogger>();

   // Пример создания NPC
   npcs.push_back(NPCFactory::createNPC("Knight", "Arthur", 50, 50));
   npcs.push_back(NPCFactory::createNPC("Elf", "Legolas", 100, 100));
   npcs.push_back(NPCFactory::createNPC("Druid", "Merlin", 200, 200));

   // Печать списка NPC
   for (const auto& npc : npcs) {
      std::cout << npc->getName() << " (" << npc->getType() << ") at ("
                << npc->getX() << ", " << npc->getY() << ")" << std::endl;
   }

   // Запуск боевого режима
   BattleVisitor battle(150.0, npcs);  // Указать радиус
   battle.addObserver(consoleLogger);
   battle.addObserver(fileLogger);

   return 0;
}
