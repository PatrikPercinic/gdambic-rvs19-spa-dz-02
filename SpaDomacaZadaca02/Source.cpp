#include <SFML/Graphics.hpp>
#include "Celije.h"
#include "Life.h"
#include "Testiranje.h"
#include "Text.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1600, 1000), "Patrik Percinic GameOfLife", sf::Style::Default);
	window.setFramerateLimit(60);
	Celije celija(&window);
	Text text(&window);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		celija.draw();
		window.display();
	}

	return 0;
}