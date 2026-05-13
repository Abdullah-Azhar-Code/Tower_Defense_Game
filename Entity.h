#ifndef ENTITY_H
#define ENTITY_H

#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Entity
{
protected:
	Vector2f pos;
public:
	Entity(Vector2f pos);
	virtual ~Entity() = 0 { };
	virtual void draw(RenderWindow& window) = 0 {};
	Vector2f get_position()const;
};

#endif
