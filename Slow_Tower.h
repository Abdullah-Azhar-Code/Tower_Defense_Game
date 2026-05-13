#ifndef SLOW_TOWER_H
#define SLOW_TOWER_H

#include<iostream>
#include<SFML/Graphics.hpp>
#include "Tower.h"
#include "Enemy.h"

using namespace std;
using namespace sf;

class SlowTower : public Tower
{
public:
    SlowTower(Vector2f pos, float rng, float rate, int dmg) :Tower(pos, rng, rate, dmg) {};
    void draw(RenderWindow& window) override;
    void attack(Enemy* enemies[], int enemyCount) override;
};
#endif
