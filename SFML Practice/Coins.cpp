#include <sfml\Graphics.hpp>
#include "Coins.h"
#include "Player.h"

const sf::RenderWindow &window;
std::vector<Coins*> coinVec;
int score;
Player player;

Coins::Coins(const sf::RenderWindow &window, sf::Vector2f size, Player player) {	
		coin.setSize(size);
		coin.setFillColor(sf::Color::Yellow);
		player = player;
}

void loadCoins() {	
	Coins coin1(window, { 20, 20 }, player);
	Coins coin2(window, { 20, 20 }, player);
	coinVec.push_back(&coin1);
	coinVec.push_back(&coin2);

	coin1.setPos({ 50, 600 });
	coin2.setPos({ 100, 600 });
}

bool isCollidingWithCoin(Coin *coin) {
	if (player.getGlobalBounds().intersects(coin->getGlobalBounds())) {
		return true;
	}
	return false;
}

void calcScore(){
for (int i = 0; i < coinVec.size(); i++) {
	if (player.isCollidingWithCoin(coinVec[i])) {
		coinVec[i]->setPos({ 422234, 423432 });
		score++;
		ssScore.str("");
		ssScore << "Score " << score;
		lblScore.setString(ssScore.str());
	}
}
}