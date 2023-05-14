#include "Text.h"
#include <sstream>

using namespace std;

Text::Text(sf::RenderWindow* window)
{
	this->window = window;
	if (!font.loadFromFile("Retronoid.ttf"))
	{
		throw _exception();
	}
}

void Text::draw(unsigned long int ukupanBroj)
{
	sf::Text text;
	sf::Text text2;
	sf::Text text3;
	text2.setPosition(20, 910);
	text.setPosition(20, 950);
	text3.setPosition(1350, 960);

	text.setFont(font); 
	text2.setFont(font); 
	text3.setFont(font); 

	text3.setFillColor(sf::Color::Green);
	//text2.setFillColor(sf::Color::Black);
	//text3.setFillColor(sf::Color::Black);

	std::stringstream ss;
	ss << "Ukupan broj promjena: ";
	ss << ukupanBroj;
	text.setString(ss.str());
	text2.setString("WASD za pomicanje, +/- za zoom, r za resetiranje pozicije.");
	text3.setString("Patrik Percinic 1RP2");

	text.setCharacterSize(30); 
	text2.setCharacterSize(30); 
	text3.setCharacterSize(20); 

	window->draw(text);
	window->draw(text2);
	window->draw(text3);
}
