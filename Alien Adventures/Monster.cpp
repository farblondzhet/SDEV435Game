#include "Monster.h"



Monster::Monster(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position)
{
	daisy.setSize(size);
	daisy.setOrigin(size / 2.0f);
	daisy.setTexture(texture);
	daisy.setPosition(position);
}


Monster::~Monster()
{
}

void Monster::Draw(sf::RenderWindow & window)
{
	window.draw(daisy);
}