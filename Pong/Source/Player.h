#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Ball.h"
class Player
{
	friend class FieldManager;
	private:
		float x, y;
		float xOffset, yOffset;
		bool up, down, play2, aiPlayer;
	public:
		Player(bool player2);
		Player(bool player2, bool ai);
		Player();
		sf::Sprite player;
		float ballYVelocity;
		void reset();
		void input(sf::Event event);
		void update();
		void draw(sf::RenderWindow &win);
};

#endif