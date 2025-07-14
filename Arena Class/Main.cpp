#include <iostream>
#include "Arena.h"

int main()
{
    Arena arena(5);

    Type fireStrong[TYPE_COUNT] = { Wind };
    Type fireWeak[TYPE_COUNT] = { Water, Earth };

    Type waterStrong[TYPE_COUNT] = { Fire, };
    Type waterWeak[TYPE_COUNT] = { Wind };

    Type windStrong[TYPE_COUNT] = { Water, Earth };
    Type windWeak[TYPE_COUNT] = { Fire };

    Type earthStrong[TYPE_COUNT] = { Fire, Wind };
    Type earthWeak[TYPE_COUNT] = { Wind };


    Monster* fire = new Monster("Monster A", 100, 40, 20, Fire, fireStrong, fireWeak);
    Monster* water = new Monster("Monster B", 100, 40, 20, Water, waterStrong, waterWeak);
    Monster* wind = new Monster("Monster C", 100, 40, 20, Wind, windStrong, windWeak);
    Monster* earth = new Monster("Monster D", 100, 40, 20, Earth, earthStrong, earthWeak);

    arena.addMonster(*fire);
    arena.addMonster(*water);
    arena.addMonster(*wind);
    arena.addMonster(*earth);

    for (int i = 0; i < 10; i++)
    {
        arena.goToRound();
        arena.getTopHp();
    }

    delete fire;
    delete water;
    delete wind;
    delete earth;
}