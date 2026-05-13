#ifndef ENEMY_H
#define ENEMY_H

#include<iostream>
#include <SFML/Graphics.hpp>
#include "Entity.h"

using namespace std;
using namespace sf;

class Enemy:public Entity
{
protected:
	float speed;
	int hp;
	int target_index;
	int max_hp;
	Sprite sprite;
public:
	Enemy(Vector2f pos, float sp, int health, int tar_ind) :Entity(pos),speed(sp),hp(health),target_index(tar_ind),max_hp(health) {};
	virtual ~Enemy() = 0 { };
	virtual void move(Vector2f path[], int &path_size) = 0;
	virtual void draw(RenderWindow& window) = 0 {};
	virtual void draw_hp(RenderWindow& window);
	void set_texture(Texture& tex);
	void set_scale(float scaleX, float scaleY);
	virtual void take_damage(int damage);
	bool Is_dead() const;
	int get_hp() const;
};
#endif