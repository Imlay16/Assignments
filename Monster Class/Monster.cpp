#include "Monster.h"
#include <string.h>
#include <iostream>
using namespace std;

Monster::Monster(const char* name, int hp, int attack, int defense, Type type)
{
	setName(name);
	this->hp = hp;
	this->attack = attack;
	this->defense = defense;
	this->type = type;
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

void Monster::onAttack(Monster *monster)
{
	Type onAttackedtype = monster->getType();
	int damage = monster->getAttack();

	cout << this->name << "(" << TypeToString[this->type] << ") " << "Attacks " << monster->name << "(" << TypeToString[monster->getType()] << ")" << endl;

	float damageRate = type_damage_table[this->type][onAttackedtype];
	monster->onDamaged(damage * damageRate);
}

Monster::~Monster()
{
	delete[] this->name;
}