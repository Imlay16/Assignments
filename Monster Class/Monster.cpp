#include "Monster.h"
#include <string.h>
#include <iostream>
using namespace std;

Monster::Monster(const char* name, int hp, int attack, int defense, Type type, Type strong[], Type weak[])
{
	setName(name);
	this->hp = hp;
	this->attack = attack;
	this->defense = defense;
	this->type = type;

	for (int i = 0; i < sizeof(*strong) / sizeof(Type); i++)
	{
		strongType[i] = strong[i];
	}

	for (int i = 0; i < sizeof(*weak) / sizeof(Type); i++)
	{
		weakType[i] = weak[i];
	}
}

Monster::Monster(const Monster& monster) {
	
	if (monster.name != nullptr) {
		name = new char[strlen(monster.name) + 1];
		strcpy_s(name, strlen(monster.name) + 1, monster.name);
	}
	else {
		name = nullptr;
	}

	hp = monster.hp;
	attack = monster.attack;
	defense = monster.defense;
	type = monster.type;

	for (int i = 0; i < TYPE_COUNT; i++)
	{
		strongType[i] = monster.strongType[i];
	}

	for (int i = 0; i < TYPE_COUNT; i++)
	{
		weakType[i] = monster.weakType[i];
	}
}

void Monster::setName(const char* name)
{
	if (this->name != nullptr)
	{
		delete[] this->name;
	}

	this->name = new char[NAME_LEN + 1];

	strcpy_s(this->name, NAME_LEN + 1, name);
}

void Monster::onDamaged(int damage)
{
	if (this->defense >= damage)
	{
		cout << this->name << " Got 0 Damage" << endl;
		return;
	}

	this->hp = this->hp - (damage - this->defense);

	cout << this->name << " Got Damaged: " << damage << endl;

	cout << this->name;

	if (this->hp <= 0)
	{
		cout << " Died" << endl;
	}	
	else
	{
		cout << " Left HP: " << this->hp << endl;
	}
}

bool Monster::isDead()
{
	if (this->hp <= 0)
	{
		return true;
	}
	return false;
}

void Monster::onAttack(Monster *monster)
{
	Type onAttackedtype = monster->getType();
	int damage = this->attack;

	cout << this->name << "(" << TypeToString[this->type] << ") " << "Attacks " << monster->name << "(" << TypeToString[monster->getType()] << ")" << endl;

	damage *= processDamageRate(monster->getType());
	monster->onDamaged(damage);
}

float Monster::processDamageRate(Type type)
{
	float multiplier = 1.0f;

	for (int i = 0; i < TYPE_COUNT; i++)
	{
		if (strongType[i] == type)
		{
			multiplier = 1.5f;
			return multiplier;
		}
	}

	for (int i = 0; i < TYPE_COUNT; i++)
	{
		if (weakType[i] == type)
		{
			multiplier = 0.5f;
			return multiplier;
		}
	}

	return multiplier;
}

Monster::~Monster()
{
	delete[] this->name;
}