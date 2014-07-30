#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
class Ball
{
	friend class FieldManager;
	private:
		float x, y;
		float xVelocity, yVelocity;
	public:
		Ball();
		
		bool collideP1, collideP2, player1Wins, player2Wins;
		int p1Score, p2Score;
		sf::Sprite ball;
		sf::SoundBuffer wall, win;
		sf::Sound wallSound, winSound;
		void update();
		void draw(sf::RenderWindow &win);
		void wait();
		void reset();
	//
};
#endif