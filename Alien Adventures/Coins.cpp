#include "Coins.h"



Coins::Coins(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position)
{
	daisy.setSize(size);
	daisy.setOrigin(size / 2.0f);
	daisy.setTexture(texture);
	daisy.setPosition(position);
}


Coins::~Coins()
{
}

void Coins::Draw(sf::RenderWindow & window)
{
	window.draw(daisy);
}