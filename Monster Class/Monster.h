#pragma once
#define NAME_LEN 32
#define TYPE_COUNT 4

static float type_damage_table[TYPE_COUNT][TYPE_COUNT] = {
	//Fire, Water, Wind, Earth
	{1.0f, 0.5f, 1.5f, 0.5f}, // Fire
	{1.5f, 1.0f, 0.5f, 1.0f}, // Water
	{0.5f, 1.5f, 1.0f, 1.5f}, // Wind
	{1.5f, 1.0f, 1.5f, 1.0f}, // Earth
};

static const char* TypeToString[TYPE_COUNT] = { "Fire", "Water", "Wind", "Earth" };

enum Type
{
	Fire,
	Water,
	Wind,
	Earth,
};

class Monster
{
private:
	char* name;
	int hp;
	int attack;
	int defense;
	Type type;
	void setName(const char *name);
	void onDamaged(int damage);

public:
	Monster(const char* name, int hp, int attack, int defense, Type type);
	int getAttack() { return attack; }
	Type getType() { return type; }
	void onAttack(Monster* monster);
	~Monster();
};

