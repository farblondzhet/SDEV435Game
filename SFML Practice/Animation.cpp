#include "Animation.h"



Animation::Animation(sf::Texture* texture, sf::Vector2u imgNum, float switchTime)
{
	this->imgNum = imgNum;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currImg.x = 0;

	textRect.width = texture->getSize().x / float(imgNum.x);
	textRect.height = texture->getSize().y / float(imgNum.y);

	
}


Animation::~Animation()
{
}

void Animation::Update(int row, int col, float deltaTime, bool faceRight)
{
	currImg.y = row;
	currImg.x = col;
	totalTime += deltaTime;

	if (totalTime >= switchTime) {
		
		totalTime -= switchTime;
		currImg.x++;
		currImg.y++;

			if (currImg.x >= 4) {
				currImg.x = 0;
		}
	
	}	
	textRect.top = currImg.y * textRect.height;

	if (faceRight) {
		textRect.left = currImg.x * textRect.width;
		textRect.width = abs(textRect.width);
	}
	else {
		textRect.left = (currImg.x + 1) * abs(textRect.width);
		textRect.width = -abs(textRect.width);
	}
}


