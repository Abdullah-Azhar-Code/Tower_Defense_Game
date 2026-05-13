#ifndef GAME_H
#define GAME_H

#include<iostream>
#include <SFML/Graphics.hpp>
#include"Enemy.h"

using namespace std;
using namespace sf;

class Game
{
private:
	Texture base_enemy, fast_enemy, tank_enemy, flying_enemy;
	Texture cannon_tower, sniper_tower, machine_gun_tower, slow_tower;
	Texture Map, Background;
	Sprite map, background;
	Enemy* enemy[100];
	Tower* tower[20];
	Vector2f *path;
	int path_size;
	int gold;
	int lives;
	int wave;
	bool game_over;
	bool game_won;
	int selected_tower;
	int current_wave;
	int enemies_spawned;
	int enemies_killed;
	int max_enemies_in_wave;
	Clock spawn_clock;
	float spawn_delay;
	Music background_music;
	Font font;
	Text lives_text;
	Text gold_text;
	Text wave_text;
	Text status_text;
public:
	Game();
	void load_font();
	void load_music();
	void update_hud();
	void load_enemies();
	void load_towers();
	void load_map();
	void load_background();
	void set_map();
	void set_background();
	void set_path();
	void spawn_enemy();
	void Events_Handling(RenderWindow& window);
	void update();
	void draw(RenderWindow& window);
	~Game();
};
#endif
