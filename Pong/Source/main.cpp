#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Ball.h"
#include "Player.h"
#include "FieldManager.h"



int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1024,650), "Pong!", sf::Style::Close, settings);
	std::cout << "Welcome to Pong! - Ben Euden\n\nControls:"
			  << "\n\n-Player 1: W,S\n"<<"-Player2: Up,Down \n"<< "-ESC: Main Menu"
			  << "\n\nClick to begin!" << std::endl;
	bool mainMenu = true;
	bool running = false;
	bool p1Selected = true;
	bool p2Selected = false;

	//load textures
	sf::Texture logo = sf::Texture();
	sf::Texture quit = sf::Texture();
	sf::Texture p1Win = sf::Texture();
	sf::Texture p2Win = sf::Texture();
	sf::Texture p1 = sf::Texture();
	sf::Texture p2 = sf::Texture();
	sf::Texture pText = sf::Texture();
	pText.loadFromFile("sprites/player.png");
	logo.loadFromFile("sprites/logo.png");
	quit.loadFromFile("sprites/quit.png");
	p1Win.loadFromFile("sprites/P1Win.png");
	p2Win.loadFromFile("sprites/P2Win.png");
	p1.loadFromFile("sprites/P1.png");
	p2.loadFromFile("sprites/P2.png");
	
	//set up sprites
	sf::Sprite menuLogo = sf::Sprite(logo);
	sf::Sprite quitLogo = sf::Sprite(quit);
	sf::Sprite p1WinLogo = sf::Sprite(p1Win);
	sf::Sprite p2WinLogo = sf::Sprite(p2Win);
	sf::Sprite player1Logo = sf::Sprite(p1);
	sf::Sprite player2Logo = sf::Sprite(p2);
	//set sprites origins
	menuLogo.setOrigin(logo.getSize().x/2, logo.getSize().y/2);
	player1Logo.setOrigin(p1.getSize().x/2, p1.getSize().y/2);
	player2Logo.setOrigin(p2.getSize().x/2, p2.getSize().y/2);

	FieldManager fm;
	
	

	//load sounds
	sf::SoundBuffer wall, win;
	wall.loadFromFile("sounds/pongwall.wav");
	win.loadFromFile("sounds/pongwin.wav");
	
	//allocate the sound buffers to sounds
	sf::Sound wallSound(wall);
	sf::Sound winSound(win);
	
	//set the sounds
	
	while (window.isOpen())
	{
		//get a window event. defined in SFML 2.0
		sf::Event event;
		
		if(mainMenu){	// If we're in the main menu, wait for game selection.
			while(window.pollEvent(event))
				{
					// draw the logo and player selectors
					menuLogo.setPosition(512,300);
					player1Logo.setPosition(380,415);
					player2Logo.setPosition(640, 415);
					window.clear();
					window.draw(menuLogo);
					window.draw(player1Logo);
					window.draw(player2Logo);
					window.display();
					
					if(event.type == sf::Event::Closed)
						window.close();
					if(event.type == sf::Event::KeyPressed 
						&& event.key.code == sf::Keyboard::Escape){
						window.close();
					}
					
					if(event.type == sf::Event::MouseButtonPressed 
						&& player1Logo.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
							fm = FieldManager(true, false);
							fm.p.player.setTexture(pText);
							fm.p2.player.setTexture(pText);
							fm.b.wallSound = wallSound;
							fm.b.winSound = winSound;
							running = true;
							mainMenu = false;
					}
					if(event.type == sf::Event::MouseButtonPressed 
						&& player2Logo.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
							fm = FieldManager();
							fm.p.player.setTexture(pText);
							fm.p2.player.setTexture(pText);
							fm.b.wallSound = wallSound;
							fm.b.winSound = winSound;
							running = true;
							mainMenu = false;
					}
				}
		}
		
		else if(running){
			if(fm.play1Win == true)
				{
					while(window.pollEvent(event))
					{
						p1WinLogo.setPosition(20, 100);
						quitLogo.setPosition(344, 315);
						window.clear();
						window.draw(p1WinLogo);
						window.draw(quitLogo);
						window.display();
						if(event.type == sf::Event::MouseButtonPressed 
							&& quitLogo.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
								running = false;
								mainMenu = true;
						}
						if(event.type == sf::Event::Closed)
								window.close();
						if(event.type == sf::Event::KeyPressed 
							&& event.key.code == sf::Keyboard::Escape){
							running = false;
							mainMenu = true;
						}
					}
				}
				
				else if(fm.play2Win)
				{
					while(window.pollEvent(event))
					{
						p2WinLogo.setPosition(20, 100);
						quitLogo.setPosition(344, 315);
						window.clear();
						window.draw(p2WinLogo);
						window.draw(quitLogo);
						window.display();
						if(event.type == sf::Event::MouseButtonPressed 
							&& quitLogo.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
								running = false;
								mainMenu = true;
						}
						if(event.type == sf::Event::Closed)
								window.close();
						if(event.type == sf::Event::KeyPressed 
							&& event.key.code == sf::Keyboard::Escape){
							running = false;
							mainMenu = true;
						}
					}
				}
				else{
					window.clear();

				//do drawing here.
					while(window.pollEvent(event))
					{	fm.input(event);
						if(event.type == sf::Event::Closed)
								window.close();
						if(event.type == sf::Event::KeyPressed 
							&& event.key.code == sf::Keyboard::Escape){
							running = false;
							mainMenu = true;
						}
				
					}
			
				
			
					if(running){
				
						fm.update();
						fm.draw(window);
						window.display();
					}
				}
			
		}
	}
	return 0;
}