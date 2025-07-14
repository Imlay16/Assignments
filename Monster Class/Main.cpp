// Monsters.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include "Monster.h"

int main()
{
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
    
    fire->onAttack(water);
    //fire->onAttack(wind);
    //fire->onAttack(earth);

    //water->onAttack(fire);
    //water->onAttack(wind);
    water->onAttack(earth);

    //wind->onAttack(fire);
    //wind->onAttack(water);
    wind->onAttack(earth);
    
    earth->onAttack(fire);
    earth->onAttack(water);
    //earth->onAttack(wind);

    delete fire; 
    delete water; 
    delete wind; 
    delete earth;
}

