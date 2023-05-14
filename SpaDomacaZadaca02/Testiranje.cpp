#include "Testiranje.h"




Testiranje::Testiranje(sf::RenderWindow* window)
{
	this->window = window;
}

void Testiranje::draw()
{
	sf::Texture tex;
	tex.create(1600, 900);

	sf::Image img;
	img.create(1600, 900);
	for (int i = 0; i < 1600; i++)
	{
		for (int j = 0; j < 900; j++)
		{
			img.setPixel(i, j, sf::Color(i%255,j%255,i+j%255));
		}
		
	}
	for (int i = 0; i < 1600; i++)
	{
		img.setPixel(i, 1, sf::Color::White);
		img.setPixel(i, 899, sf::Color::White);
	}
	//img.setPixel(10, 20, sf::Color::Red);
	tex.update(img);

	sf::Sprite sprite;
	sprite.setTexture(tex);
	//sprite.setScale(10, 10);
	sprite.setPosition(0, 0);

	window->draw(sprite);
}
