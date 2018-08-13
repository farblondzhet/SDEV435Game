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

