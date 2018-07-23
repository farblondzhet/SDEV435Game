#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Collider.h"

class Coins{
public:
	Coins(const sf::RenderWindow &window, sf::Vector2f size, Player player) {
		coin.setSize(size);
		coin.setFillColor(sf::Color::Yellow);
	}

	void drawTo(sf::RenderWindow &window) {
		window.draw(coin);
	}

	sf::FloatRect getGlobalBounds() {
		return coin.getGlobalBounds();
	}

	void setPos(sf::Vector2f newPos) {
		coin.setPosition(newPos);
	}
private:
	sf::RectangleShape coin;
};