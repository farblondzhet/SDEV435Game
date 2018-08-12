#include <SFML\Graphics.hpp>
#include <iostream>
#include "Collider.h"
#include "Animation.h"
#include "Player.h"
#include <vector>
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
	int score = 0;
	int monsterScore = 0;
	int lives = 5;
	int lvl;

	//Load Textures
	sf::Texture textureDaisy;
	textureDaisy.loadFromFile("DaisySprite.png");
	sf::Texture flag;
	flag.loadFromFile("flag.png");
	sf::Texture coin;
	coin.loadFromFile("coin.png");
	
	//Add Player vector
	Player player(&textureDaisy, sf::Vector2u(3, 2), 0.3f, 300.0f, 200);
	
	
	sf::Texture backgrnd;
	backgrnd.loadFromFile("Lvl1_Background.png");
	sf::Texture ground;
	ground.loadFromFile("ground.png");
	sf::Texture platformText;
	platformText.loadFromFile("platformText.png");
	sf::Texture monsterText;
	monsterText.loadFromFile("lvl1_monster.png");



	//Add Platforms
	std::vector<Platform> platformsOne;
	platformsOne.push_back(Platform(&platformText, sf::Vector2f(300.0f, 100.0f), sf::Vector2f(700.0f, 300.0f)));
	platformsOne.push_back(Platform(&platformText, sf::Vector2f(150.0f, 100.0f), sf::Vector2f(900.0f, 200.0f)));
	platformsOne.push_back(Platform(&platformText, sf::Vector2f(150.0f, 100.0f), sf::Vector2f(1100.0f, 100.0f)));
	platformsOne.push_back(Platform(&platformText, sf::Vector2f(300.0f, 100.0f), sf::Vector2f(1500.0f, 50.0f)));
	platformsOne.push_back(Platform(&ground, sf::Vector2f(2049.0f, 180.0f), sf::Vector2f(1024.0f, 458.0f)));	

	//Add Coins
	std::vector<Coins> coinsOne;	
	coinsOne.push_back(Coins(&coin, sf::Vector2f(20.0f, 20.0f), sf::Vector2f(850.0f, 100.0f)));
	coinsOne.push_back(Coins(&coin, sf::Vector2f(20.0f, 20.0f), sf::Vector2f(900.0f, 100.0f)));
	coinsOne.push_back(Coins(&coin, sf::Vector2f(20.0f, 20.0f), sf::Vector2f(950.0f, 100.0f)));		

	std::vector<Platform> monstersOne;
	monstersOne.push_back(Platform(&monsterText, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(740.0f, 200.0f)));
	monstersOne.push_back(Platform(&monsterText, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(1600.0f, -50.0f)));

	std::vector<Platform> flags;
	flags.push_back(Platform(&flag, sf::Vector2f(50.0f, 190.0f), sf::Vector2f(2000, 305)));

	float deltaTime = 0.0f;
	sf::Clock clock;

	//Add background
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

			switch (evnt.type){
				case sf::Event::Closed:
				window.close();
				break;

				/*case sf::Event::Resized:
				ResizeView(window, view);
				break;*/
				//sf::Vector2f visibleArea = sf::Vector2f((float)evnt.size.width, (float)evnt.size.height);


			}


		}

		player.Update(deltaTime);

		sf::Vector2f direction;

		for (Platform& platform : platformsOne) {
			if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
				player.OnCollision(direction);
		}


		for (Platform& flags : flags) {
			if (flags.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f)) {
				player.OnCollision(direction);
				lvl = 2;
			}
		}

		spriteBackground.setPosition(0.0f, -800.0f);
		view.setCenter(player.GetPosition());
		window.clear();
		window.setView(view);
		window.draw(spriteBackground);		
		player.Draw(window);		

		for (Platform& platform : platformsOne) {
			platform.Draw(window);
		}
		
		//Monsters
		//for all elements in monster vector
		for (int i = 0; i < monstersOne.size(); i++) {
			//draw to window
			monstersOne[i].Draw(window);
			//if colliding with player and hit from the top, erase from vector and ++ kill count
			if (monstersOne[i].GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f)
				&& player.OnCollision(direction)) {
				monstersOne.erase(monstersOne.begin() + i);
				monsterScore++;						
			}		
			else if (monstersOne[i].GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f 
				&& player.loseHeart())) {			
				monstersOne.erase(monstersOne.begin() + i);
				lives--;										
			}
		}		

		for (int i = 0; i < coinsOne.size(); i++) {
			if (!coinsOne[i].GetCoinCollider().CheckCollision(player.GetCoinCollider(), direction)) {
				coinsOne[i].Draw(window);				
			}
			else { 
				coinsOne.erase(coinsOne.begin() + i);
				score++;
			}
		}	


		for (Platform& flags : flags) {
			flags.Draw(window);
		}
		
		
		window.display();		
		
	}

	cout << lives << endl;
	cout << monsterScore;
	return 0;
}