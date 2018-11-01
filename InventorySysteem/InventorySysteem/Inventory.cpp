#include "stdafx.h"
#include "Inventory.h"
#include "Item.h"

Inventory::Inventory()
{
}
void Inventory::Add(Item * item)
{
	itemList.push_back(item);
}
void Inventory::CreateItem(std::string name, int durability)
{

	if (itemList.size() < inventorySize) {
		Item * g = new Item;
		g->SetName(name);
		g->SetDurability(durability);
		Add(g);
		cout << name << " added, Its durability is " << durability << "\n";
	}
	else {
		cout << "Your inventory is full" << "\n";
	}
}
void Inventory::See(string name) 
{
	bool exists = false;
	int count = 0;

	list<Item*>::iterator it;
	for (it = itemList.begin(); it != itemList.end(); it++) {

		if (name == "fullinventory")
		{
			cout << (*it)->name << " it has a durability of " << (*it)->durability << "\n";
			bool exists = true;
		}
		if ((*it)->name == name)
		{
			cout << (*it)->name << " has a durability of " << (*it)->durability << "\n";
			bool exists = true;
		}
		else
		{
			count++;
		}

		if (count >= itemList.size() && !exists)
			cout << "'" << name << "'" << " does not exist" << "\n";


	}

}
void Inventory::Use(string name)
{
	bool exists = false;
	int count = 0;

	list<Item*>::iterator it;
	for (it = itemList.begin(); it != itemList.end();)
	{
		if ((*it)->name == name)
		{
			(*it)->durability--;
			cout << (*it)->name << " now has a durability of " << (*it)->durability << "\n";

			if ((*it)->durability <= 0)
			Delete((*it)->name);


			it = itemList.end();
			exists = true;
		}
		else
		{
			it++;
			count++;
		}
		if (count >= itemList.size() && !exists)
			cout << "'" << name << "'" << " does not exist" << "\n";

	}
}
void Inventory::Delete(string name) 
{
	bool exists = false;
	int count = 0;

	list<Item*>::iterator it;
	for (it = itemList.begin(); it != itemList.end();)
	{
		if ((*it)->name == name){
			cout << (*it)->name << " broke noob" << "\n";
			delete *it;
			it = itemList.erase(it);
			it = itemList.end();
			exists = true;
		}
		else {
			it++;
			count++;
		}
		if (count >= itemList.size() && !exists)
			cout << "'"<< name << "'" << " does not exist" << "\n";
	}
}


Inventory::~Inventory()
{
}
