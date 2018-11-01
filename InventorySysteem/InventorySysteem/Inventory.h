#pragma once
#include "stdafx.h"
#include "Item.h"
#include <list> 
#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
class Inventory
{
public:
	list<Item*> itemList;
	void add(Item * item)
	{
		itemList.push_back(item);
	}
	void createItem(std::string name, int durability)
	{
		Item * g = new Item;
		g->SetName(name);
		g->SetDurability(durability);
		add(g);
		cout << name << " added, Its durability is " << durability << "\n";
	}
	void see(string name) {
		list<Item*>::iterator it;
		for (it = itemList.begin(); it != itemList.end(); it++){

			if (name == "fullinventory")
			cout << (*it)->name << " it has a durability of " << (*it)->durability << "\n";
			if((*it)->name == name)
			cout << (*it)->name << " has a durability of "<< (*it)->durability <<  "\n";

		}

	}

	void use(string name) 
	{
		list<Item*>::iterator it;
		for (it = itemList.begin(); it != itemList.end(); it++)
		{
			if ((*it)->name == name)
			{
			(*it)->durability--;
			cout << (*it)->name << " now has a durability of " << (*it)->durability << "\n";
			}
			if ((*it)->durability <= 0)
			{

				cout << (*it)->name << " broke " << "\n";
				delete *it;
				it = itemList.erase(it);
			}

		}
	}
	Inventory();
	~Inventory();
};

