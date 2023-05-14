#include "Celije.h"
#include <chrono>
#include <thread>

	using namespace std::this_thread;     // sleep_for, sleep_until
	using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
	using std::chrono::system_clock;



Celije::Celije(sf::RenderWindow* window)
{

	this->window = window;

	tex.create(REDAKA, STUPACA);
	img.create(REDAKA, STUPACA);
	zeljenaVelicina.x = 1600.f;
	zeljenaVelicina.y = 900.f;

}

void Celije::draw()
{
	//crtanje jedne slike/sprita puno brze od vector arraya ili obicnih objekta
	alive = life.GetLife();
	Text text(window);
	ukupanBroj += life.GetBrojCelija();
	

	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (alive[i][j])
				img.setPixel(i, j, sf::Color::Green);
			else
				img.setPixel(i, j, sf::Color(0,0,0,0));
		}
	}
	//postavljanje texture na sprite
	tex.update(img);
	sprite.setTexture(tex);
	//skaliranje na velicinu ekrana 
	sprite.setScale(
		(zeljenaVelicina.x / sprite.getLocalBounds().width)*skala,
		(zeljenaVelicina.y / sprite.getLocalBounds().height)*skala);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		sprite.move(0, 20*skala);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		sprite.move(20*skala, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		sprite.move(0, -20*skala);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		sprite.move(-20*(skala), 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
	{
		if (skala<=3)
		{
		skala += 0.3;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))
	{
		if (skala >= 0.5)
		{
			skala -= 0.3;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		sprite.setPosition(0, 0);
		skala = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		limit = false;
	}
	if (limit)
	{
		sleep_until(system_clock::now() + 2s);
	}
	

	window->draw(sprite);
	life.step();
	text.draw(ukupanBroj);
}
