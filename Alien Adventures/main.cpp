#include <SFML\Graphics.hpp>
#include <iostream>
#include "Collider.h"
#include "Animation.h"
#include "Player.h"
#include <vector>
#include "Platform.h"
#include "Database.h"

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
	int lvlComp = 1;
	

	//Load Textures
	sf::Texture textureDaisy;
	textureDaisy.loadFromFile("DaisySprite.png");
	sf::Texture flag;
	flag.loadFromFile("flag.png");
	sf::Texture coin;
	coin.loadFromFile("coin.png");
	sf::Texture backgrnd;
	backgrnd.loadFromFile("skyBackground.png");
	
	//Add Player vector
	Player player(&textureDaisy, sf::Vector2u(3, 2), 0.3f, 300.0f, 200);
	
	
	sf::Texture ground;
	ground.loadFromFile("ground.png");
	sf::Texture platformTextOne;
	platformTextOne.loadFromFile("platformText.png");
	sf::Texture platformTextTwo;
	platformTextTwo.loadFromFile("platformTwo.png");
	sf::Texture monsterText;
	monsterText.loadFromFile("lvl1_monster.png");



	//Level One Platforms
	std::vector<Platform> platformsOne;
	platformsOne.push_back(Platform(&platformTextOne, sf::Vector2f(300.0f, 100.0f), sf::Vector2f(700.0f, 300.0f)));
	platformsOne.push_back(Platform(&platformTextOne, sf::Vector2f(150.0f, 100.0f), sf::Vector2f(900.0f, 200.0f)));
	platformsOne.push_back(Platform(&platformTextOne, sf::Vector2f(150.0f, 100.0f), sf::Vector2f(1100.0f, 100.0f)));
	platformsOne.push_back(Platform(&platformTextOne, sf::Vector2f(300.0f, 100.0f), sf::Vector2f(1500.0f, 50.0f)));
	platformsOne.push_back(Platform(&ground, sf::Vector2f(2049.0f, 180.0f), sf::Vector2f(1024.0f, 458.0f)));	

	//Level Two Platforms
	std::vector<Platform> platformsTwo;
	platformsTwo.push_back(Platform(&platformTextTwo, sf::Vector2f(300.0f, 100.0f), sf::Vector2f(1200.0f, 0.0f)));
	platformsTwo.push_back(Platform(&platformTextTwo, sf::Vector2f(150.0f, 100.0f), sf::Vector2f(1000.0f, 100.0f)));
	platformsTwo.push_back(Platform(&platformTextTwo, sf::Vector2f(150.0f, 100.0f), sf::Vector2f(800.0f, 300.0f)));
	platformsTwo.push_back(Platform(&platformTextTwo, sf::Vector2f(300.0f, 100.0f), sf::Vector2f(500.0f, 400.0f)));

	//Level One Coins
	std::vector<Coins> coinsOne;	
	coinsOne.push_back(Coins(&coin, sf::Vector2f(20.0f, 20.0f), sf::Vector2f(850.0f, 100.0f)));
	coinsOne.push_back(Coins(&coin, sf::Vector2f(20.0f, 20.0f), sf::Vector2f(900.0f, 100.0f)));
	coinsOne.push_back(Coins(&coin, sf::Vector2f(20.0f, 20.0f), sf::Vector2f(950.0f, 100.0f)));	
	//Level Two Coins
	std::vector<Coins> coinsTwo;
	coinsTwo.push_back(Coins(&coin, sf::Vector2f(20.0f, 20.0f), sf::Vector2f(850.0f, 100.0f)));
	coinsTwo.push_back(Coins(&coin, sf::Vector2f(20.0f, 20.0f), sf::Vector2f(900.0f, 100.0f)));
	coinsTwo.push_back(Coins(&coin, sf::Vector2f(20.0f, 20.0f), sf::Vector2f(950.0f, 100.0f)));

	//Level One Monsters
	std::vector<Platform> monstersOne;
	monstersOne.push_back(Platform(&monsterText, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(740.0f, 200.0f)));
	monstersOne.push_back(Platform(&monsterText, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(1600.0f, -50.0f)));
	//Level Two Monsters
	std::vector<Platform> monstersTwo;
	monstersTwo.push_back(Platform(&monsterText, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(740.0f, 200.0f)));
	monstersTwo.push_back(Platform(&monsterText, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(1600.0f, -50.0f)));

	std::vector<Platform> flags;
	flags.push_back(Platform(&flag, sf::Vector2f(50.0f, 190.0f), sf::Vector2f(2000, 305)));
	//flags.push_back(Platform(&flag, sf::Vector2f(50.0f, 190.0f), sf::Vector2f(500, 400)));

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

			}


		}

		Database database;
		database.Insert("player one", 45, 2, 1);
		database.Fetch();
		cout << stderr;
		cout << stdout;

		player.Update(deltaTime);

		sf::Vector2f direction;

		spriteBackground.setPosition(0.0f, -800.0f);
		view.setCenter(player.GetPosition());
		window.clear();
		window.setView(view);
		window.draw(spriteBackground);			

		if (lvlComp == 0) {
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

			for (int i = 0; i < flags.size(); i++)
				flags[i].Draw;
		}

		if (lvlComp == 1) {
			//Monsters
			//for all elements in monster vector
			for (int i = 0; i < monstersTwo.size(); i++) {
				//draw to window
				monstersTwo[i].Draw(window);
				//if colliding with player and hit from the top, erase from vector and ++ kill count
				if (monstersTwo[i].GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f)
					&& player.OnCollision(direction)) {
					monstersTwo.erase(monstersTwo.begin() + i);
					monsterScore++;
				}
				else if (monstersTwo[i].GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f
					&& player.loseHeart())) {
					monstersTwo.erase(monstersTwo.begin() + i);
					lives--;
				}
			}


			for (int i = 0; i < coinsTwo.size(); i++) {
				if (!coinsTwo[i].GetCoinCollider().CheckCollision(player.GetCoinCollider(), direction)) {
					coinsTwo[i].Draw(window);
				}
				else {
					coinsTwo.erase(coinsTwo.begin() + i);
					score++;
				}
			}

			for (int i = 0; i < flags.size(); i++)
				flags[i].Draw;
		}
		
		
		window.display();		
		
	}

	//cout << "lives" << lives << endl;
	//cout << monsterScore <<endl;
	//cout << lvlComp;	
	return 0;
}