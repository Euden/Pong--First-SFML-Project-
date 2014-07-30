#include "Player.h"

Player::Player()
{
	x=100;
	y=200;
	up = false;
	down = false;
	play2=false;
	aiPlayer = false;
	xOffset = 0.1f;
	yOffset = 0.5f;
	//player.setOrigin(player.getLocalBounds().height/2, player.getLocalBounds().width);

	
}

Player::Player(bool player2)
{
	x=900;
	y=200;
	up = false;
	down = false;
	play2 = player2;
	aiPlayer = false;
	xOffset = 0.1f;
	yOffset = 0.5f;
	
}

Player::Player(bool ai, bool player2)
{
	x=900;
	y=200;
	up = false;
	down = false;
	play2 = player2;
	aiPlayer = ai;
	xOffset = 0.1f;
	ballYVelocity = 0;
	yOffset = 0.25f;
}

void Player::input(sf::Event event)
{
	switch(event.type)
	{
		case sf::Event::KeyPressed:
			if(event.key.code == sf::Keyboard::W && !play2 && !aiPlayer)
			{
				up = true;
			}
			else if(event.key.code == sf::Keyboard::S && !play2 && !aiPlayer)
			{
				
				down = true;
			}
			else if(event.key.code == sf::Keyboard::Up && play2 && !aiPlayer)
			{
				
				up = true;
			}
			else if(event.key.code == sf::Keyboard::Down && play2 && !aiPlayer)
			{
				
				down = true;
			}
			
		break;
		case sf::Event::KeyReleased:
			 
			if(event.key.code == sf::Keyboard::W && !play2 && !aiPlayer)
			{
				up = false;
			}
			else if(event.key.code == sf::Keyboard::S && !play2 && !aiPlayer)
			{
				down = false;
			}
			else if(event.key.code == sf::Keyboard::Up && play2 && !aiPlayer)
			{
				up = false;
			}
			else if(event.key.code == sf::Keyboard::Down && play2 && !aiPlayer)
			{
				down = false;
			}
			
			break;
	}

	if(aiPlayer && ballYVelocity < 0)
	{		
		up = true;
		down = false;
	}
	else if(aiPlayer && ballYVelocity > 0)
	{	up = false;	
		down = true;
	}
	

}

void Player::update()
{
	if(up ==true && down == false && y > 0)
	{
		y-=yOffset;
	}

	if(down ==true && up == false &&  y < 550 )
	{
		
		y+=yOffset;
	}
	
}

void Player::draw(sf::RenderWindow &win)
{
	win.draw(player);
	player.setPosition(x, y);
}

void Player::reset()
{
	if(play2 || aiPlayer)
		player.setPosition(900, 200);
	else
		player.setPosition(100, 200);
}