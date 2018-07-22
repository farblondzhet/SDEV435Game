
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Animation.h"
#include "Player.h"

using namespace std;



int main() {

	sf::RenderWindow window(sf::VideoMode(1024, 504), "Alien Adventure");
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1024, 504));
	sf::RectangleShape daisy(sf::Vector2f(100,150));
	daisy.setPosition({ 100, 400 });

	sf::Texture textureDaisy;
	textureDaisy.loadFromFile("DaisySprite.png");
	daisy.setTexture(&textureDaisy);
	sf::Texture backgrnd;

	sf::Vector2u textureSize = textureDaisy.getSize();
	textureSize.x /= 10;
	textureSize.y /= 2;

	daisy.setTextureRect(sf::IntRect(textureSize.x * 0, textureSize.y * 2, textureSize.x, textureSize.y));	
	Player player({ 100, 150 });
	player.setPos({ 50, 400 });


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

	const int groundHeight = 400;
	const float gravitySpeed = 0.3;
	bool isJumping = false;

		
	while (window.isOpen()) {

		sf::Event evnt;

		const float moveSpeed = 0.2;


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			player.move({ 0, -moveSpeed });
			isJumping = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			player.move({ moveSpeed, 0 });
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			player.move({ -moveSpeed, 0 });
		}

		//Event Loop:
		while (window.pollEvent(evnt)) {
			switch (evnt.type) {

			case sf::Event::Closed:
				window.close();

			case sf::Event::KeyReleased:
				isJumping = false;
			}
		}

		//Gravity Logic:
		if (player.getY() < groundHeight && isJumping == false) {
			player.move({ 0, gravitySpeed });
		}


		view.setCenter(player.GetPosition());
		window.clear(sf::Color(172, 241, 227));
		window.setView(view);
		window.draw(spriteBackground);
		player.Draw(window);
		window.display();
		}
	}
