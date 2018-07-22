#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
#include <iostream>

class Player
{
public:
	Player(sf::Vector2f size) {
		daisy.setSize(size);
	}

	void Draw(sf::RenderWindow &window) {
		window.draw(daisy);
	}

	sf::Vector2f GetPosition() { return daisy.getPosition(); }	


	void move(sf::Vector2f distance) {
		daisy.move(distance);
	}

	void setPos(sf::Vector2f newPos) {
		daisy.setPosition(newPos);
	}

	const float getY() {
		return daisy.getPosition().y;
	}


private:
	sf::RectangleShape daisy;
	//Animation animation;
	int row;
	int col;	
	bool faceRight;
	
	bool canJump;	
};

