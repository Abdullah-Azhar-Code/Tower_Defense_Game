#ifndef BASIC_ENEMY_H
#define BASIC_ENEMY_H

#include<iostream>
#include <SFML/Graphics.hpp>
#include "Enemy.h"

using namespace std;
using namespace sf;

class BasicEnemy : public Enemy
{
public:
    BasicEnemy(Vector2f pos, float sp, int health, int tar_ind) :Enemy(pos, sp, health, tar_ind) {};
    void move(Vector2f path[], int &pathSize) override;
    void draw(RenderWindow& window) override;
    //void take_damage(int damage) override;
};
#endif
