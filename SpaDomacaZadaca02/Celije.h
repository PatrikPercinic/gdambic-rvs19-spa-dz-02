#pragma once
#include "Life.h"
#include "Text.h"
#include<SFML/Graphics.hpp>
class Celije
{
private:
	sf::RenderWindow* window;
	Life life;
	sf::Texture tex;
	sf::Image img;
	sf::Sprite sprite;
	vector<vector<bool>> alive;
	sf::Vector2f zeljenaVelicina;
	float skala = 1;
	unsigned long int ukupanBroj = 0;
	static const unsigned int STUPACA = 180;
	static const unsigned int REDAKA = 320;
	static const unsigned int VELICINA = 5;

public:
	Celije(sf::RenderWindow* window);
	void draw();
};

