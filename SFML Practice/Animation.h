#pragma once
#include <sfml\Graphics.hpp>
#include "Collider.h"
class Animation
{
public:
//Function Declarations
	Animation(sf::Texture* texture, sf::Vector2u imgNum, float switchTime);
	~Animation();
	 
	void Update(int row, float deltaTime, bool faceRight);

//Variable Declarations
	sf::IntRect textRect;

private:
	sf::Vector2u imgNum;
	sf::Vector2u currImg;
	

	float totalTime;
	float switchTime;
};

