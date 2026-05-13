#ifndef SNIPER_TOWER_H
#define SNIPER_TOWER_H

#include<iostream>
#include<SFML/Graphics.hpp>
#include "Tower.h"
#include "Enemy.h"

using namespace std;
using namespace sf;

class SniperTower : public Tower
{
public:
    SniperTower(Vector2f pos, float rng, float rate, int dmg) :Tower(pos, rng, rate, dmg) {};
    void draw(RenderWindow& window) override;
    void attack(Enemy* enemies[], int enemyCount) override;
};
#endif
