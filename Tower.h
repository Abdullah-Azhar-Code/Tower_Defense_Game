#ifndef TOWER_H
#define TOWER_H

#include<iostream>
#include<SFML/Graphics.hpp>
#include "Entity.h"
#include "Enemy.h"

using namespace std;
using namespace sf;

class Tower : public Entity
{
protected:
    float range;
    float fire_rate;
    int damage;
	Sprite sprite;
public:
    Tower(Vector2f pos, float rng, float rate, int dmg) :Entity(pos), range(rng), fire_rate(rate), damage(dmg) {};
    virtual ~Tower() = 0 { };
    virtual void attack(Enemy* enemies[], int enemyCount) = 0 {};
    virtual void draw(RenderWindow& window) = 0 {};
    float getRange() const;
    void set_scale(float scaleX, float scaleY);
	void set_texture(Texture& tex);
};
#endif
