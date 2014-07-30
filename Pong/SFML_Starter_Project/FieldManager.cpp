#include "FieldManager.h"
#include "Player.h"
#include <string>
#include <sstream>
#include <vector>



FieldManager::FieldManager()
{
	
		p = Player();
		p2 = Player(play2);
		b = Ball();
	
		play1Win = false;
		play2Win = false;
	for(int s = 0; s < 10; s++){
		sf::Texture tex;
		std::ostringstream os;
		os << "sprites/" << s << ".png";
		tex.loadFromFile(os.str());
		scoresp1.push_back(tex);
		scoresp2.push_back(tex);
	}
	for(int i =0; i < 10; i++){
		scoreSpritesP1.push_back(sf::Sprite(scoresp1[i]));
		scoreSpritesP2.push_back(sf::Sprite(scoresp2[i]));
	}
	
}

FieldManager::FieldManager(bool AI, bool P2)
{
		b = Ball();
		p = Player();
		p2 = Player(AI, P2);


		play1Win = false;
		play2Win = false;

		for(int s = 0; s < 10; s++){
			sf::Texture tex;
			std::ostringstream os;
			os << "sprites/" << s << ".png";
			tex.loadFromFile(os.str());
			scoresp1.push_back(tex);
			scoresp2.push_back(tex);
		}
	for(int i =0; i < 10; i++){
		scoreSpritesP1.push_back(sf::Sprite(scoresp1[i]));
		scoreSpritesP2.push_back(sf::Sprite(scoresp2[i]));
	}
}

void FieldManager::input(sf::Event event)
{
	p.input(event);
	p2.input(event);
}

void FieldManager::draw(sf::RenderWindow &win)
{
	win.draw(score1);
	win.draw(score2);
	
	p.draw(win);
	p2.draw(win);
	b.draw(win);
	//draw scores
	
	
}

void FieldManager::update()
{
	if(b.ball.getGlobalBounds().intersects(p.player.getGlobalBounds()))
	{
		b.collideP1 = true;
	}
	else if(b.ball.getGlobalBounds().intersects(p2.player.getGlobalBounds()))
	{
		b.collideP2 = true;

	}
	b.update();
	if(p2.aiPlayer)
		p2.ballYVelocity = b.yVelocity;
	p.update();
	p2.update();
	
	if(b.player1Wins)
	{
		play1Win = true;
	}
	else if(b.player2Wins)
	{
		play2Win = true;
	}
	else {
		playerScore1 = b.p1Score;
		playerScore2 = b.p2Score;
		auto p = scoresp1.begin();
		score1 = sf::Sprite(scoresp1[playerScore1]);
		score2 = sf::Sprite(*(p + playerScore2));
	
		score1.setPosition(200,100);
		score2.setPosition(775, 100);
	}
}

void FieldManager::reset()
{
		p.reset();
		p2.reset();
		b.reset();
	
}