#include "Player.h"




Player::Player(sf::Texture* texture, sf::Vector2u imgNum, float switchTime, float speed, float jumpHeight) :
	animation(texture, imgNum, switchTime)
{
	row = 1;
	col = 0;
	faceRight = true;

	daisy.setSize(sf::Vector2f(150.0f, 100.0f));
	daisy.setOrigin(daisy.getSize() / 2.0f);	
	daisy.setTexture(texture);
}


Player::~Player()
{
}
