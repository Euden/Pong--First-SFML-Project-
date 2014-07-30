
#include <random>
#include "Ball.h"

#define START_POSX 512.0f
#define START_POSY 325.0f
#define VELOCITY_STARTX 0.2f
#define VELOCITY_STARTY 0.2f


Ball::Ball()
{
	//set initial size and position
	x = START_POSX;
	y = START_POSY;
	xVelocity = (rand() % 2 ? VELOCITY_STARTX : -VELOCITY_STARTX);
	yVelocity =  (rand() % 2 ? VELOCITY_STARTY : -VELOCITY_STARTY);
	collideP1 = false;
	collideP2 = false;
	player1Wins = false;
	player2Wins = false;
	//load the ball sprite
	sf::Texture ballTex;
	ballTex.loadFromFile("sprites/ball.png");
	ball = sf::Sprite(ballTex);
	
	
	//set the score
	p1Score = 0;
	p2Score = 0;

	
	
	
	ball.setPosition(x, y);
}

void Ball::update()
{
	//check we're not colliding with anything
	if(collideP1){
		xVelocity = -xVelocity +0.05f;
		ball.setPosition(ball.getPosition().x +10, ball.getPosition().y);
		wallSound.play();
		collideP1 = false;
	}
	else if(collideP2)
	{
		xVelocity = -xVelocity -0.05f;
		ball.setPosition(ball.getPosition().x -10, ball.getPosition().y);
		wallSound.play();
		collideP2 = false;
	}

		if(ball.getPosition().x < 50){
			//Player 2 has scored!
			winSound.play();
			if(p2Score != 9)
				p2Score++;
			else
				player2Wins = true;
			x = START_POSX;
			y = START_POSY;
			xVelocity = (rand() % 2 ? VELOCITY_STARTX : -VELOCITY_STARTX);
			yVelocity =  (rand() % 2 ? VELOCITY_STARTY : -VELOCITY_STARTY);
			ball.setPosition(x, y);
			wait();
		}
		else if(ball.getPosition().x > 950){
			//Player 1 has scored!
			if(p1Score != 9)
				p1Score++;
			else
				player1Wins = true;
			x = START_POSX;
			y = START_POSY;
			
			winSound.play();
			xVelocity = (rand() % 2 ? VELOCITY_STARTX : -VELOCITY_STARTX);
			yVelocity =  (rand() % 2 ? VELOCITY_STARTY : -VELOCITY_STARTY);
			ball.setPosition(x, y);
			wait();
		}
		if(ball.getPosition().y < 0){
			wallSound.play();
			y= 0;
			yVelocity = -yVelocity;
			
		}
		if(ball.getPosition().y > 630){
			wallSound.play();
			y = 620;
			yVelocity = -yVelocity;
			
		}

	
}

void ::Ball::draw(sf::RenderWindow &win){
	win.draw(ball);
	ball.move(xVelocity, yVelocity);
}



void ::Ball::wait()
{
	
	sf::Time t2 = sf::milliseconds(10);
	sf::sleep(t2);
	
}

void ::Ball::reset()
{
	x = START_POSX;
	y = START_POSY;
	xVelocity = (rand() % 2 ? VELOCITY_STARTX : -VELOCITY_STARTX);
	yVelocity =  (rand() % 2 ? VELOCITY_STARTY : -VELOCITY_STARTY);
	ball.setPosition(x, y);
	p1Score = 0;
	p2Score = 0;
	wait();
}