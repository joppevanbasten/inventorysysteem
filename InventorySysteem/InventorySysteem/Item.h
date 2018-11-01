#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>
class Item
{

	using String = std::string;
public:
	int durability;
	String name;
public:
	bool operator == (const Item& s) const { return name == s.name && durability == s.durability; }
	bool operator != (const Item& s) const { return !operator==(s); }
	void SetDurability(int setDurability);
	void SetName(String setName);
	Item() : name("unknown"), durability(1) {}
	Item(const String& namee, int& durabilityy) : name(namee), durability(durabilityy) {}
	const String& GetName() const { return name; }
	~Item();
};

