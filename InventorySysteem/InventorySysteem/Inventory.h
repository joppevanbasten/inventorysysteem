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
	int inventorySize = 5;
	list<Item*> itemList;
	void Add(Item * item);
	void CreateItem(std::string name, int durability);
	void See(string name);
	void Use(string name);
	void ChangeSize(int size);
	void Delete(string name);
	Inventory();
	~Inventory();
};

