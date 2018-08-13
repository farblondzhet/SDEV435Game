#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Collider.h"
#include "Coins.h"

class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imgNum, float switchTime, float speed, float jumpHeight);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow &window);
	bool OnCollision(sf::Vector2f direction);	
	bool loseHeart();
	void changePosition(float x, float y);

	sf::Vector2f GetPosition() { return daisy.getPosition(); }
	Collider GetCollider() { return Collider(daisy); }
	CoinCollider GetCoinCollider() { return CoinCollider(daisy); }
	


private:
	sf::RectangleShape daisy;
	Animation animation;
	unsigned int row;
	unsigned int col;
	float speed;
	bool faceRight;

	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
	bool damage;
};