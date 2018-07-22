#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imgNum, float switchTime, float speed, float jumpHeight);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow &window);
	void OnCollision(sf::Vector2f direction);

	sf::Vector2f GetPosition() { return daisy.getPosition(); }
	Collider GetCollider() { return Collider(daisy); }


private:
	sf::RectangleShape daisy;
	Animation animation;
	int row;
	int col;
	float speed;
	bool faceRight;

	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
};