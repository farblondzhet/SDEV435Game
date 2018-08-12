#include "Player.h"




Player::Player(sf::Texture* texture, sf::Vector2u imgNum, float switchTime, float speed, float jumpHeight) :
	animation(texture, imgNum, switchTime)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 1;
	col = 0;
	faceRight = true;

	daisy.setSize(sf::Vector2f(100.0f, 150.0f));
	daisy.setOrigin(daisy.getSize() / 2.0f);
	daisy.setPosition(500.0f, 226.0f);
	daisy.setTexture(texture);
}


Player::~Player()
{
}


void Player::Update(float deltaTime)
{
	velocity.x = 0.0f;

	////////////////////////
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		velocity.x -= speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		velocity.x += speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump) {
		canJump = false;  
		velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
	}

	velocity.y += 981.0f * deltaTime;

	if (velocity.x == 0.0f) {
		row = 0;
		col = 0;

	}
	else {
		row = 1;

		if (velocity.x > 0.0f) {
			faceRight = true;
		}
		else {
			faceRight = false;
		}
	}

	animation.Update(row, deltaTime, faceRight);
	daisy.setTextureRect(animation.textRect);
	daisy.move(velocity * deltaTime);
}

void Player::Draw(sf::RenderWindow &window)
{
	window.draw(daisy);
}


///////////////////////////////
bool Player::OnCollision(sf::Vector2f direction)
{		

	if (direction.x < 0.0f) {

		//Colliding with object on left
		velocity.x = 0.0f;
		damage = true;
	}
	else if (direction.x > 0.0f) {

		//Colliding with object on right 
		velocity.x = 0.0f;
		damage = true;
	}

	if (direction.y < 0.0f) {

		//Touching Ground or monster
		velocity.y = 0.0f;
		canJump = true;		
	}
	else if (direction.y > 0.0f) {

		//Colliding with object above
		velocity.y = 0.0f;
		damage = true;
	}

	return damage;	
}

/////////////////////////////
bool Player::loseHeart() {
	return damage;	
}
