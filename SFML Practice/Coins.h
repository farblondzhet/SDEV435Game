#pragma once
#include <SFML\Graphics.hpp>
#include "CoinCollider.h"

class Coins
{
public:
	Coins(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position);
	~Coins();

	void Draw(sf::RenderWindow &window);
	CoinCollider GetCoinCollider() { return CoinCollider(daisy); }

private:
	sf::RectangleShape daisy;
};

