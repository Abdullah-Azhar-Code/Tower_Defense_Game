#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include"Entity.h"
#include"Enemy.h"
#include"Basic_Enemy.h"
#include"Fast_Enemy.h"
#include"Flying_Enemy.h"
#include"Tank_Enemy.h"
#include"Tower.h"
#include"Canon_Tower.h"
#include"Sniper_Tower.h"
#include"MachineGun_Tower.h"
#include"Slow_Tower.h"
#include"Game.h"

using namespace std;
using namespace sf;

Entity::Entity(Vector2f pos)
{
	this->pos = pos;
}
Vector2f Entity::get_position() const 
{
	return pos;
}


void Tower::set_texture(Texture& tex)
{
	sprite.setTexture(tex);
}
void Tower::set_scale(float scaleX, float scaleY)
{
	sprite.setScale(scaleX, scaleY);
}
float Tower::getRange()const
{
	return range;
}

void CannonTower::draw(RenderWindow& window)
{
	sprite.setPosition(pos);
	window.draw(sprite);
}
void CannonTower::attack(Enemy* enemies[], int enemyCount)
{
	for (int i = 0; i < enemyCount; i++)
	{
		if (enemies[i] != nullptr && !enemies[i]->Is_dead())
		{
			Vector2f enemy_Pos = enemies[i]->get_position();
			float dx = enemy_Pos.x - pos.x;
			float dy = enemy_Pos.y - pos.y;
			float distance = sqrt(dx * dx + dy * dy);
			if (distance <= range)
			{
				enemies[i]->take_damage(damage);
				break;
			}
		}
	}
}

void SniperTower::draw(RenderWindow& window)
{
	sprite.setPosition(pos);
	window.draw(sprite);
}
void SniperTower::attack(Enemy* enemies[], int enemyCount)
{
	for (int i = 0; i < enemyCount; i++)
	{
		if (enemies[i] != nullptr && !enemies[i]->Is_dead())
		{
			Vector2f enemy_Pos = enemies[i]->get_position();
			float dx = enemy_Pos.x - pos.x;
			float dy = enemy_Pos.y - pos.y;
			float distance = sqrt(dx * dx + dy * dy);
			if (distance <= range)
			{
				enemies[i]->take_damage(damage * 2);
				break;
			}
		}
	}
}

void MachineGunTower::draw(RenderWindow& window)
{
	sprite.setPosition(pos);
	window.draw(sprite);
}
void MachineGunTower::attack(Enemy* enemies[], int enemyCount)
{
	for (int i = 0; i < enemyCount; i++)
	{
		if (enemies[i] != nullptr && !enemies[i]->Is_dead())
		{
			Vector2f enemy_Pos = enemies[i]->get_position();
			float dx = enemy_Pos.x - pos.x;
			float dy = enemy_Pos.y - pos.y;
			float distance = sqrt(dx * dx + dy * dy);
			if (distance <= range)
			{
				enemies[i]->take_damage(damage);
			}
		}
	}
}

void SlowTower::draw(RenderWindow& window)
{
	sprite.setPosition(pos);
	window.draw(sprite);
}
void SlowTower::attack(Enemy* enemies[], int enemyCount)
{
	for (int i = 0; i < enemyCount; i++)
	{
		if (enemies[i] != nullptr && !enemies[i]->Is_dead())
		{
			Vector2f enemy_Pos = enemies[i]->get_position();
			float dx = enemy_Pos.x - pos.x;
			float dy = enemy_Pos.y - pos.y;
			float distance = sqrt(dx * dx + dy * dy);
			if (distance <= range)
			{
				enemies[i]->take_damage(damage / 2);
			}
		}
	}
}


void Enemy::take_damage(int damage)
{
	hp = hp - damage;
	if (hp < 0)
	{
		hp = 0;
	}
}
bool Enemy::Is_dead() const
{
	return hp <= 0;
}
int Enemy::get_hp() const
{
	return hp;
}

void Enemy::set_texture(Texture& tex)
{
	sprite.setTexture(tex);
}
void Enemy::set_scale(float scaleX, float scaleY)
{
	sprite.setScale(scaleX, scaleY);
}
void Enemy::draw_hp(RenderWindow& window)
{
	RectangleShape backBar;
	backBar.setSize(Vector2f(40, 5));
	backBar.setFillColor(Color::Red);

	backBar.setPosition(pos.x-5, pos.y - 10);

	RectangleShape hpBar;

	float hpPercent = (float)hp / max_hp;

	hpBar.setSize(Vector2f(40 * hpPercent, 5));

	hpBar.setFillColor(Color::Green);

	hpBar.setPosition(pos.x-5, pos.y - 10);

	window.draw(backBar);
	window.draw(hpBar);
}


void BasicEnemy::draw(RenderWindow& window)
{
	sprite.setPosition(pos);
	window.draw(sprite);
}
void BasicEnemy::move(Vector2f path[], int& pathSize)
{
	if (target_index >= pathSize)
	{
		return;
	}
	Vector2f target = path[target_index];
	Vector2f direction = target - pos;
	float distance = sqrt(direction.x * direction.x + direction.y * direction.y);
	if (distance < speed)
	{
		pos = target;
		target_index++;
	}
	else
	{
		direction /= distance;
		pos += direction * speed;
	}
}
void FastEnemy::draw(RenderWindow& window)
{
	sprite.setPosition(pos);
	window.draw(sprite);
}
void FastEnemy::move(Vector2f path[], int& pathSize)
{
	if (target_index >= pathSize)
	{
		return;
	}
	Vector2f target = path[target_index];
	Vector2f direction = target - pos;
	float distance = sqrt(direction.x * direction.x + direction.y * direction.y);
	float effective_speed = speed * 2.0f;
	if (distance < effective_speed)
	{
		pos = target;
		target_index++;
	}
	else
	{
		direction /= distance;
		pos += direction * effective_speed;
	}
}
void TankEnemy::draw(RenderWindow& window)
{
	sprite.setPosition(pos);
	window.draw(sprite);
}
void TankEnemy::move(Vector2f path[], int& pathSize)
{
	if (target_index >= pathSize)
	{
		return;
	}
	Vector2f target = path[target_index];
	Vector2f direction = target - pos;
	float distance = sqrt(direction.x * direction.x + direction.y * direction.y);
	float effective_speed = speed * 0.5f;
	if (distance < effective_speed)
	{
		pos = target;
		target_index++;
	}
	else
	{
		direction /= distance;
		pos += direction * effective_speed;
	}
}
void FlyingEnemy::draw(RenderWindow& window)
{
	sprite.setPosition(pos);
	window.draw(sprite);
}
void FlyingEnemy::move(Vector2f path[], int& pathSize)
{
	if (path==nullptr||index >= 6)
	{
		return;
	}
	Vector2f target = path[fly[index]];
	Vector2f direction = target - pos;
	float distance = sqrt(direction.x * direction.x + direction.y * direction.y);
	if (distance < speed)
	{
		pos = target;
		index++;
	}
	else
	{
		direction /= distance;
		pos += direction * speed;
	}
}

Game::Game()
{
	path = nullptr;
	path_size = 0;
	gold = 500;
	lives = 10;
	wave = 1;
	selected_tower = 0;
	current_wave = 1;
	enemies_spawned = 0;
	enemies_killed = 0;
	max_enemies_in_wave = 5;
	spawn_delay = 2.0f;
	game_over = false;
	game_won = false;
	for (int i = 0; i < 100; i++)
	{
		enemy[i] = nullptr;
	}
	for (int i = 0; i < 4; i++)
	{
		tower[i] = nullptr;
	}
}
void Game::load_font()
{
	if (!font.loadFromFile("Font/Inter_28pt-SemiBold.ttf"))
	{
		cout << "----------Error Loading Font----------" << endl;
		return;
	}

	lives_text.setFont(font);
	lives_text.setCharacterSize(24);
	lives_text.setFillColor(Color::Red);
	lives_text.setPosition(10, 10);

	gold_text.setFont(font);
	gold_text.setCharacterSize(24);
	gold_text.setFillColor(Color::Yellow);
	gold_text.setPosition(540, 10);

	wave_text.setFont(font);
	wave_text.setCharacterSize(24);
	wave_text.setFillColor(Color::White);
	wave_text.setPosition(1100, 10);

	status_text.setFont(font);
	status_text.setCharacterSize(60);
	status_text.setStyle(Text::Bold);
	status_text.setPosition(640, 360);
	cout << "----------Font loaded successfully----------" << endl;
}
void Game::load_music()
{
	if (!background_music.openFromFile("Sound/silver_bullet.ogg"))
	{
		cout << "----------Error Loading Music----------" << endl;
		return;
	}
	background_music.setLoop(true);   
	background_music.setVolume(100);   
	background_music.play();
	cout << "----------Music playing----------" << endl;
}
void Game::update_hud()
{
	lives_text.setString("Lives: " + to_string(lives));
	gold_text.setString("Gold: " + to_string(gold));
	wave_text.setString("Wave: " + to_string(current_wave));
}
void Game::load_enemies()
{
	bool loaded = true;
	base_enemy.loadFromFile("enemy_pieces/base_enemy.png");
	fast_enemy.loadFromFile("enemy_pieces/fast_enemy.png");
	flying_enemy.loadFromFile("enemy_pieces/flying_enemy.png");
	tank_enemy.loadFromFile("enemy_pieces/tank_enemy.png");

	if (!base_enemy.loadFromFile("enemy_pieces/base_enemy.png"))
	{
		cout << "----------Error Loading.....enemy_pieces/base_enemy.png----------" << endl;
		loaded = false;
	}
	if (!fast_enemy.loadFromFile("enemy_pieces/fast_enemy.png"))
	{
		cout << "----------Error Loading.....enemy_pieces/fast_enemy.png----------" << endl;
		loaded = false;
	}
	if (!flying_enemy.loadFromFile("enemy_pieces/flying_enemy.png"))
	{
		cout << "----------Error Loading.....enemy_pieces/fluing_enemy.png----------" << endl;
		loaded = false;
	}
	if (!tank_enemy.loadFromFile("enemy_pieces/tank_enemy.png"))
	{
		cout << "----------Error Loading.....enemy_pieces/tank_enemy.png----------" << endl;
		loaded = false;
	}
	if (loaded)
	{
		cout << "----------Successfully loaded all enemies in the game----------" << endl;
	}
	else
	{
		cout << "----------Error loading one or more enemy textures.----------" << endl;
		return;
	}
}
void Game::load_towers()
{
	bool loaded=true;
	cannon_tower.loadFromFile("tower_pieces/cannon_tower.png");
	machine_gun_tower.loadFromFile("tower_pieces/machine_gun_tower.png");
	sniper_tower.loadFromFile("tower_pieces/sniper_tower.png");
	slow_tower.loadFromFile("tower_pieces/slow_tower.png");
	if (!cannon_tower.loadFromFile("tower_pieces/cannon_tower.png"))
	{
		cout << "----------Error Loading.....tower_pieces/cannon_tower.png" << endl;
		loaded = false;
	}
	if (!machine_gun_tower.loadFromFile("tower_pieces/machine_gun_tower.png"))
	{
		cout << "----------Error Loading.....tower_pieces/machine_gun_tower.png" << endl;
		loaded = false;
	}
	if (!sniper_tower.loadFromFile("tower_pieces/sniper_tower.png"))
	{
		cout << "----------Error Loading.....tower_pieces/sniper_tower.png" << endl;
		loaded = false;
	}
	if (!slow_tower.loadFromFile("tower_pieces/slow_tower.png"))
	{
		cout << "----------Error Loading.....tower_pieces/slow_tower.png" << endl;
		loaded = false;
	}
	if (loaded)
	{
		cout << "----------Successfully loaded all towers in the game----------" << endl;
	}
	else
	{
		cout << "----------Error loading one or more tower textures.----------" << endl;
		return;
	}
}
void Game::load_map()
{
	bool loaded = true;
	Map.loadFromFile("other_game_assets/map.png");
	if (!Map.loadFromFile("other_game_assets/map.png"))
	{
		cout << "----------Error Loading.....other_game_assets/map.png" << endl;
		loaded = false;
	}
	if (loaded)
	{
		cout << "----------Successfully loaded map in the game----------" << endl;
	}
	else
	{
		cout << "----------Error loading map.----------" << endl;
		return;
	}
}
void Game::load_background()
{
	bool loaded = true;
	Background.loadFromFile("other_game_assets/background.jpg");
	if (!Background.loadFromFile("other_game_assets/background.jpg"))
	{
		cout << "----------Error Loading.....other_game_assets/background.jpg" << endl;
		loaded = false;
	}
	if (loaded)
	{
		cout << "----------Successfully loaded background in the game----------" << endl;
	}
	else
	{
		cout << "----------Error loading background.----------" << endl;
		return;
	}
}
void Game::set_map()
{
	map.setTexture(Map);
	map.setPosition(0, 0);
	float scale_X =1280.0f / Map.getSize().x;
	float scale_Y =720.0f / Map.getSize().y;
	map.setScale(scale_X, scale_Y);
}
void Game::set_background()
{
	background.setTexture(Background);
}
void Game::set_path()
{
	int max_size = 70;             
	path = new Vector2f[max_size];
	int index = 0;

	path[index++] = Vector2f(0, 350);  

	while (index < max_size - 1)
	{
		float x = path[index - 1].x;
		float y = path[index - 1].y;
		if (x < 270 && y == 350)
		{
			path[index++] = Vector2f(min(x + 30.f, 270.f), 350);
		}
		else if (x == 270 && y < 520)
		{
			path[index++] = Vector2f(270, min(y + 30.f, 520.f));
		}
		else if (y == 520 && x < 520)
		{
			path[index++] = Vector2f(min(x + 30.f, 520.f), 520);
		}
		else if (x == 520 && y > 350)
		{
			path[index++] = Vector2f(520, max(y - 30.f, 350.f));
		}
		else if (y == 350 && x >= 520 && x < 710)
		{
			path[index++] = Vector2f(min(x + 30.f, 710.f), 350);
		}
		else if (x == 710 && y > 200)
		{
			path[index++] = Vector2f(710, max(y - 30.f, 200.f));
		}
		else if (y == 200 && x < 900)
		{
			path[index++] = Vector2f(min(x + 30.f, 900.f), 200);
		}
		else if (x == 900 && y < 350)
		{
			path[index++] = Vector2f(900, min(y + 30.f, 350.f));
		}
		else if (y == 350 && x >= 900 && x < 1080)
		{
			path[index++] = Vector2f(min(x + 30.f, 1080.f), 350);
		}
		else
		{
			break;
		} 
	}
	path[index++] = Vector2f(1280, 350);  
	path_size = index;           
}
void Game::spawn_enemy()
{
		if (enemies_spawned >= max_enemies_in_wave)
		{
			return;
		}

		if (spawn_clock.getElapsedTime().asSeconds() >= spawn_delay)
		{
			for (int i = 0; i < 100; i++)
			{
				if (enemy[i] == nullptr)
				{
					if (current_wave == 1)
					{
						enemy[i] = new BasicEnemy(Vector2f(0, 350), 1.0f, 100, 0);
						enemy[i]->set_texture(base_enemy);
					}

					else if (current_wave == 2)
					{
						enemy[i] = new FastEnemy(Vector2f(0, 350), 1.5f, 120, 0);
						enemy[i]->set_texture(fast_enemy);
					}

					else if (current_wave == 3)
					{
						enemy[i] = new TankEnemy(Vector2f(0, 350), 0.7f, 250, 0);
						enemy[i]->set_texture(tank_enemy);
					}

					else if (current_wave == 4)
					{
						enemy[i] = new FlyingEnemy(Vector2f(0, 350), 2.0f, 180, 0);
						enemy[i]->set_texture(flying_enemy);
					}

					else
					{
						if (rand() % 2 == 0)
						{
							enemy[i] = new TankEnemy(Vector2f(0, 350), 1.0f, 350, 0);
							enemy[i]->set_texture(tank_enemy);
						}
						else
						{
							enemy[i] = new FastEnemy(Vector2f(0, 350), 2.5f, 200, 0);
							enemy[i]->set_texture(fast_enemy);
						}
					}

					enemy[i]->set_scale(0.03f, 0.03f);

					enemies_spawned++;

					spawn_clock.restart();

					break;
				}
			}
		}
}
void Game::Events_Handling(RenderWindow& window)
{
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			window.close();
		}
		else if (event.type == Event::Resized)
		{
			View gameView(FloatRect(0.f, 0.f, 1280.f, 720.f));
			window.setView(gameView);
		}
		else if (event.type == Event::KeyPressed)
		{
			if (event.key.code == Keyboard::G)
			{
				selected_tower = 1;
				cout << "Cannon Tower Selected" << endl;
			}
			else if (event.key.code == Keyboard::H)
			{
				selected_tower = 2;
				cout << "Sniper Tower Selected" << endl;
			}
			else if (event.key.code == Keyboard::B)
			{
				selected_tower = 3;
				cout << "Machine Gun Tower Selected" << endl;
			}
			else if (event.key.code == Keyboard::N)
			{
				selected_tower = 4;
				cout << "Slow Tower Selected" << endl;
			}
		}
		else if (event.type == Event::MouseButtonPressed
			&& event.mouseButton.button == Mouse::Left)
		{
			cout << "Clicked! selected_tower=" << selected_tower << " gold=" << gold << endl;

			Vector2i pixelPos = Mouse::getPosition(window);
			Vector2f mousePos = window.mapPixelToCoords(pixelPos);

			for (int i = 0; i < 20; i++)
			{
				if (tower[i] == nullptr)
				{
					if (selected_tower == 1 && gold >= 50)
					{
						tower[i] = new CannonTower(mousePos, 170.f, 1.f, 25);
						tower[i]->set_texture(cannon_tower);
						tower[i]->set_scale(0.03f, 0.03f);
						gold -= 50;
						cout << ">>> Cannon placed!" << endl;
					}
					else if (selected_tower == 2 && gold >= 150)
					{
						tower[i] = new SniperTower(mousePos, 350.f, 0.5f, 60);
						tower[i]->set_texture(sniper_tower);
						tower[i]->set_scale(0.03f, 0.03f);
						gold -= 150;
						cout << ">>> Sniper placed!" << endl;
					}
					else if (selected_tower == 3 && gold >= 100)
					{
						tower[i] = new MachineGunTower(mousePos, 140.f, 5.f, 10);
						tower[i]->set_texture(machine_gun_tower);
						tower[i]->set_scale(0.03f, 0.03f);
						gold -= 100;
						cout << ">>> MachineGun placed!" << endl;
					}
					else if (selected_tower == 4 && gold >= 200)
					{
						tower[i] = new SlowTower(mousePos, 180.f, 1.f, 25);
						tower[i]->set_texture(slow_tower);
						tower[i]->set_scale(0.03f, 0.03f);
						gold -= 200;
						cout << ">>> Slow placed!" << endl;
					}
					else
					{
						cout << "Failed: selected_tower=" << selected_tower
							<< " gold=" << gold << endl;
					}
					break;
				}
			}
		}
	}
}
void Game::update()
{
	if (game_over || game_won)
	{
		return;
	}
	spawn_enemy();
	for (int i = 0; i < 100; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->move(path, path_size);
			Vector2f enem_pos = enemy[i]->get_position();
			if (enem_pos.x >= 1280)
			{
				lives--;
				delete enemy[i];
				enemy[i] = nullptr;
				if (lives <= 0)
				{
					game_over = true;
					cout << "Game Over! You have lost all your lives." << endl;
					return;
				}
				else
				{
					cout << "An enemy has reached the end! Lives remaining: " << lives << endl;
				}
			}
			else if (enemy[i]->Is_dead())
			{
				gold+=50;
				enemies_killed++;
				delete enemy[i];
				enemy[i] = nullptr;
				cout << "An enemy has been defeated! Gold: " << gold << endl;
			}
		}
	}
	for (int i = 0; i < 20; i++)
	{
		if (tower[i] != nullptr)
		{
			tower[i]->attack(enemy, 100);
		}
	}
	if (enemies_killed >= max_enemies_in_wave && enemies_spawned >= max_enemies_in_wave)
	{
		current_wave++;

		enemies_spawned = 0;
		enemies_killed = 0;

		max_enemies_in_wave += 3;

		cout << "Wave " << current_wave << " Started!" << endl;

		if (current_wave > 5)
		{
			game_won = true;
			cout << "YOU WON THE GAME!" << endl;
			return;
		}
	}
}
void Game::draw(RenderWindow& window)
{
	window.draw(map);
	for (int i = 0; i < 20; i++)
	{
		if (tower[i] != nullptr)
		{
			tower[i]->draw(window);
		}
	}
	for (int i = 0; i < 100; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->draw(window);
			enemy[i]->draw_hp(window);
		}
	}
	update_hud();
	window.draw(lives_text);
	window.draw(gold_text);
	window.draw(wave_text);
	if (game_over)
	{
		RectangleShape overlay(Vector2f(1280, 720));
		overlay.setFillColor(Color(0, 0, 0, 150));
		window.draw(overlay);
		status_text.setString("YOU LOST!");
		status_text.setFillColor(Color::Red);
		FloatRect bounds = status_text.getLocalBounds();
		status_text.setOrigin(bounds.width / 2, bounds.height / 2);
		status_text.setPosition(640, 360);
		window.draw(status_text);
	}
	if (game_won)
	{
		RectangleShape overlay(Vector2f(1280, 720));
		overlay.setFillColor(Color(0, 0, 0, 150));
		window.draw(overlay);
		status_text.setString("YOU WON!");
		status_text.setFillColor(Color::Green);
		FloatRect bounds = status_text.getLocalBounds();
		status_text.setOrigin(bounds.width / 2, bounds.height / 2);
		status_text.setPosition(640, 360);
		window.draw(status_text);
	}
}
Game::~Game()
{
	for (int i = 0; i < 100; i++)
	{
		if (enemy[i] != nullptr)
		{
			delete enemy[i];
			enemy[i] = nullptr;
		}
	}
	for (int i = 0; i < 20; i++)
	{
		if (tower[i] != nullptr)
		{
			delete tower[i];
			tower[i] = nullptr;
		}
	}
	if (path != nullptr)
	{
		delete[] path;
		path = nullptr;
	}
}
int main()
{
	srand(time(0));
	Game Tower;
	RenderWindow window(VideoMode(1280, 720), "Main_Game_window");
	window.setFramerateLimit(60);
	View gameView(FloatRect(0.f, 0.f, 1280.f, 720.f));
	window.setView(gameView);

	Tower.load_enemies();
	Tower.load_towers();
	Tower.load_map();
	Tower.load_background();
	Tower.set_map();
	Tower.set_background();
	Tower.set_path();
	Tower.load_font();
	Tower.load_music();

	while (window.isOpen())
	{
		Tower.Events_Handling(window);
		Tower.update();

		window.clear(Color::White);
		Tower.draw(window);
		window.display();
	}
	return 0;
}