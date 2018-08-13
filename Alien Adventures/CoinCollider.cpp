

#include "CoinCollider.h"



CoinCollider::CoinCollider(sf::RectangleShape& daisy) :
	daisy(daisy)
{
}


CoinCollider::~CoinCollider()
{
}

bool CoinCollider::CheckCollision(CoinCollider& other, sf::Vector2f& direction)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
	bool caughtCoin;

	//If objects are colliding
	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		return true;
	}
	else
	return false;
}
