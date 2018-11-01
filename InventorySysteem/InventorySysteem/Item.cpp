#include "stdafx.h"
#include "Item.h"

#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>

void Item::SetDurability(int setDurability) {
	durability = setDurability;
}
void Item::SetName(std::string setName) {
	name = setName;
}
Item::~Item()
{
}
