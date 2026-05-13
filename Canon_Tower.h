#ifndef CANON_TOWER_H
#define CANON_TOWER_H

#include<iostream>
#include<SFML/Graphics.hpp>
#include "Tower.h"
#include "Enemy.h"

using namespace std;
using namespace sf;

class CannonTower : public Tower
{
public:
    CannonTower(Vector2f pos, float rng, float rate, int dmg) :Tower(pos, rng, rate, dmg) {};
    void draw(RenderWindow& window) override;
    void attack(Enemy* enemies[], int enemyCount) override;
};
#endif
