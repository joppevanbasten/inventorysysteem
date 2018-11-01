// InventorySysteem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>
#include "Inventory.h"

int main()
{
	bool ended = false;
	Inventory inv;
	std::string command;
	std::string itemName;
	int durability;
	while (!ended)
	{
		std::getline(std::cin, itemName);
		std::cout << "Hello, what would you like to do? add/use/see\n";
		std::getline(std::cin, command);
		if (command == "add")
		{
			std::cout << "what would you like to add?\n";
			std::getline(std::cin, itemName);
			std::cout << "what is its durability?\n";
			std::cin >> durability;
			inv.createItem(itemName, durability);
		}
		if (command == "see")
		{
			std::cout << "what item would you like to see? ('fullinventory' for all items)\n";
			std::cin >> itemName;
			inv.see(itemName);
		}
		if (command == "use") 
		{
			std::cout << "what item would you like to use?\n";
			std::cin >> itemName;
			inv.use(itemName);
		}
		if (command == "stop") 
		{
			ended = true;
		}
	}

	return 0;
}

