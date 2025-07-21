
#include "Arena.h"

Arena::Arena(int arenaCount)
{
	this->arenaCount = arenaCount;
	monsters = new Monster* [arenaCount];
}

Arena::~Arena()
{
	for (int i = 0; i < monsterCount; i++)
	{
		delete monsters[i];
	}
	delete[] monsters;
}

void Arena::addMonster(const Monster& monster)
{
	if (monsterCount < arenaCount)
	{
		monsters[monsterCount++] = new Monster(monster);
	}
}

Monster* Arena::getTopHp()
{
	Monster* monster = monsters[0];
	int maxHp = monsters[0]->getHp();

	for (int i = 1; i < monsterCount; i++)
	{
		int curHp = monsters[i]->getHp();

		if (maxHp < curHp)
		{
			maxHp = curHp;
			monster = monsters[i];
		}
	}
	return monster;
}

void Arena::goToRound()
{
	if (monsterCount == 0)
	{
		cout << "Monsters All Died" << endl;
		return;
	}
	else if (monsterCount == 1)
	{
		cout << "Winner is " << monsters[0]->getName() << endl;
		return;
	}

	int deadIndex;
	for (int i = 0; i < monsterCount; i++)
	{
		monsters[i]->onAttack(monsters[(i + 1)%monsterCount]);
		
		if (monsters[(i + 1) % monsterCount]->isDead())
		{
			deadIndex = (i + 1) % monsterCount;

			while (deadIndex < monsterCount - 1)
			{
				monsters[deadIndex] = monsters[deadIndex + 1];
				deadIndex++;
			}

			monsterCount--;
		}
	}

	cout << "Top HP Monster: " << getTopHp()->getName() << endl;
}

