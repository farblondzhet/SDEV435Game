//#pragma once
//#include <SFML\Graphics.hpp>
//#include "Collider.h"
//
//class Coins
//{
//public:
//	Coins(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position);
//	~Coins();
//
//	void Draw(sf::RenderWindow &window);
//	Collider GetCollider() { return Collider(daisy); }
//
//private:
//	sf::RectangleShape daisy;
//};

#pragma once
#include <SFML\Graphics.hpp>

class CoinCollider
{
public:
	CoinCollider(sf::RectangleShape& daisy);
	~CoinCollider();

	void Move(float dx, float dy) { daisy.move(dx, dy); }

	bool CheckCollision(CoinCollider& other, sf::Vector2f& direction);
	sf::Vector2f GetPosition() { return daisy.getPosition(); }
	sf::Vector2f GetHalfSize() { return daisy.getSize() / 2.0f; }

private:
	sf::RectangleShape& daisy;
};

