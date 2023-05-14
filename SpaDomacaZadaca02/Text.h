#pragma once
#include<SFML/Graphics.hpp>

class Text
{
private:
	sf::RenderWindow* window;
	sf::Font font;
public:
	Text(sf::RenderWindow* window);

	void draw(unsigned long int ukupanBroj);



};

