#pragma once
#include <SFML\Graphics.hpp>
#include "Collider.h"

class Monster
{
public:
	Monster(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position);
	~Monster();

	void Draw(sf::RenderWindow &window);
	Collider GetCollider() { return Collider(daisy); }

private:
	sf::RectangleShape daisy;
};

