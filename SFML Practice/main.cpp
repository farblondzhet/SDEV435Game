#include <SFML\Graphics.hpp>
#include <iostream>
#include "Collider.h"
#include "Animation.h"
#include "Player.h"
#include "Platform.h"

using namespace std;

static const float VIEW_HEIGHT = 504;

void ResizeView(const sf::RenderWindow &window, sf::View &view) {
	float aspectRatio = float(window.getSize().x / float(window.getSize().y));
	view.setSize(1024 * aspectRatio, VIEW_HEIGHT);
}

int main() {

	sf::RenderWindow window(sf::VideoMode(1024, VIEW_HEIGHT), "Alien Adventure");
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1024, 504));

	sf::Texture textureDaisy;
	textureDaisy.loadFromFile("DaisySprite.png");
	sf::Texture backgrnd;

	Player player(&textureDaisy, sf::Vector2u(10, 2), 0.3f, 100.0f, 200);
	Platform platform1(nullptr, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(500.0f, 500.0f));

	float deltaTime = 0.0f;
	sf::Clock clock;


	if (!textureDaisy.loadFromFile("DaisySprite.png"))
	{
		std::cout << "Can't find Daisy! :(" << std::endl;
	}

	if (!backgrnd.loadFromFile("Lvl1_Background.png"))
	{
		std::cout << "Can't find Background! :(" << std::endl;
	}

	sf::Sprite spriteBackground;
	spriteBackground.setTexture(backgrnd);

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 20.0f) {
			deltaTime = 1.0 / 20.0f;
		}

		sf::Event evnt;
		while (window.pollEvent(evnt))
		{

			if (evnt.type == sf::Event::Closed)
				window.close();

			if (evnt.type == sf::Event::Resized) {
				ResizeView(window, view);
				sf::Vector2f visibleArea = sf::Vector2f((float)evnt.size.width, (float)evnt.size.height);


			}


		}

		player.Update(deltaTime);

		sf::Vector2f direction;

		platform1.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f);
		view.setCenter(player.GetPosition());
		window.clear(sf::Color(172, 241, 227));
		window.setView(view);
		window.draw(spriteBackground);
		platform1.Draw(window);
		player.Draw(window);
		window.display();
	}


	return 0;
}