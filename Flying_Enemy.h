#ifndef FLYING_ENEMY_H
#define FLYING_ENEMY_H

#include<iostream>
#include <SFML/Graphics.hpp>
#include "Enemy.h"

using namespace std;
using namespace sf;

class FlyingEnemy : public Enemy
{
private:
    int fly[6];
    int index;
public:
    FlyingEnemy(Vector2f pos, float sp, int health, int tar_ind) :Enemy(pos, sp, health, tar_ind)
    {
        fly[0] = 0;
        fly[1] = 9;
        fly[2] = 30;
        fly[3] = 37;
        fly[4] = 60;
        fly[5] = 61;
        index = 0;
    };
    void move(Vector2f path[], int& pathSize) override;
    void draw(RenderWindow& window) override;
    //void take_damage(int damage) override;
};

#endif
