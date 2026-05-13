#ifndef FAST_ENEMY_H
#define FAST_ENEMY_H

#include<iostream>
#include <SFML/Graphics.hpp>
#include "Enemy.h"

using namespace std;
using namespace sf;

class FastEnemy : public Enemy
{
public:
    FastEnemy(Vector2f pos, float sp, int health, int tar_ind) :Enemy(pos, sp, health, tar_ind) {};
    void move(Vector2f path[], int& pathSize) override;
    void draw(RenderWindow& window) override;
    //void take_damage(int damage) override;
};
#endif
