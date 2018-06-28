#pragma once
#include <SFML\Graphics.hpp>

class Collider
{
public:
	Collider(sf::RectangleShape& daisy);
	~Collider();

	void Move(float dx, float dy) { daisy.move(dx, dy); }

	bool CheckCollision(Collider& other, sf::Vector2f &direction, float push);
	sf::Vector2f GetPosition() { return daisy.getPosition(); }
	sf::Vector2f GetHalfSize() { return daisy.getSize() / 2.0f; }

private:
	sf::RectangleShape& daisy;
};

