#ifndef MACHINEGUN_TOWER_H
#define MACHINEGUN_TOWER

#include<iostream>
#include<SFML/Graphics.hpp>
#include "Tower.h"
#include "Enemy.h"

using namespace std;
using namespace sf;

class MachineGunTower : public Tower
{
public:
    MachineGunTower(Vector2f pos, float rng, float rate, int dmg) :Tower(pos, rng, rate, dmg) {};
    void draw(RenderWindow& window) override;
    void attack(Enemy* enemies[], int enemyCount) override;
};
#endif
