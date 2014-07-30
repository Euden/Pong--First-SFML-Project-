#ifndef FIELDMANAGER_H
#define FIELDMANAGER_H


#include "Player.h"
#include "Ball.h"
#include <vector>


class FieldManager
{
private:
	sf::Sprite score1, score2;
	std::vector<sf::Sprite> scoreSpritesP1, scoreSpritesP2;
	std::vector<sf::Texture> scoresp1, scoresp2;
	sf::RectangleShape topBorder, bottomBorder;
	int playerScore1, playerScore2;
	
	public:
		FieldManager();
		FieldManager(bool AI, bool P2);
		bool play2, play1Win, play2Win;
		Player p;
		Player p2;
		Ball b;
		void input(sf::Event event);
		void update();
		void draw(sf::RenderWindow &win);
		void reset();
		//

};


#endif