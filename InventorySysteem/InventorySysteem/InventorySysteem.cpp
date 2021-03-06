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
		std::cout << "Hello, what would you like to do? add/use/see/delete\n";
		std::getline(std::cin, command);
		if (command == "add")
		{
			if (inv.itemList.size() < inv.inventorySize)
			{
				std::cout << "what would you like to add?\n";
				std::getline(std::cin, itemName);
				std::cout << "what is its durability?\n";
				std::cin >> durability;
				while (std::cin.fail()) {
					std::cout << "That is not a number, try again." << std::endl;
					std::cin.clear();
					std::cin.ignore(256, '\n');
					std::cin >> durability;
				}
				inv.CreateItem(itemName, durability);
			}
			else {
				cout << "Your inventory is full" << "\n";
			}
		}
		else if (command == "see")
		{
			std::cout << "what item would you like to see? ('fullinventory' for all items)\n";
			std::cin >> itemName;
			inv.See(itemName);
		}
		else if (command == "use") 
		{
			std::cout << "what item would you like to use?\n";
			std::cin >> itemName;
			inv.Use(itemName);
		}
		else if (command == "changesize")
		{

		}
		else if (command == "delete")
		{
			std::cout << "what item would you like to delete?\n";
			std::cin >> itemName;
			inv.Delete(itemName);
		}
		else if (command == "stop") 
		{
			ended = true;
		}
	}

	return 0;
}

