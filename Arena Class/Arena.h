#pragma once
#include "Monster.h"
#pragma comment(lib, "MonsterLib.lib")
#include <iostream>

#define MAX_MONSTER_COUNT 100

using namespace std;

class Arena
{
private:
	int arenaCount;
	int monsterCount = 0;
	Monster** monsters;
	void DeleteDeadMonster();


public:
	Arena();
	Arena(int);
	~Arena();

	void addMonster(const Monster&);
	Monster* getTopHp();
	void goToRound();
};

