#pragma once
#define NAME_LEN 32

enum Type
{
	Fire,
	Water,
	Wind,
	Earth,
	TYPE_COUNT
};

static const char* TypeToString[TYPE_COUNT] = { "Fire", "Water", "Wind", "Earth" };

class Monster
{
private:
	char* name;
	int hp;
	int attack;
	int defense;
	Type type;

	Type strongType[TYPE_COUNT];
	Type weakType[TYPE_COUNT];

	void setName(const char *name);
	void onDamaged(int damage);

public:
	Monster(const char* name, int hp, int attack, int defense, Type type, Type strong[], Type weak[]);
	int getAttack() { return attack; }
	Type getType() { return type; }
	void onAttack(Monster* monster);
	float processDamageRate(Type type);
	~Monster();
};

