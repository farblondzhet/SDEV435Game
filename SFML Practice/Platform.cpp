#include "Platform.h"



Platform::Platform(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position)
{
	daisy.setSize(size);
	daisy.setOrigin(size / 2.0f);
	daisy.setTexture(texture);
	daisy.setPosition(position);
}


Platform::~Platform()
{
}

void Platform::Draw(sf::RenderWindow & window)
{
	window.draw(daisy);
}
