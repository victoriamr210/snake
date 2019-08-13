#pragma once
#include <iostream>
#include "snake.hpp"
#include "things.hpp"

#include <SFML/Graphics.hpp>
using namespace std;

// enum dir {UP, DOWN, LEFT, RIGHT};

class game{

	public:
		sf::RenderWindow window;
		snake snek;
		food fod;
		direction dir=STOP;
		// sf::RectangleShape snake(sf::Vector2f(120.f, 50.f));
		// sf::RectangleShape food(sf::Vector2f(120.f, 50.f));

		game(){
			this->window.create(sf::VideoMode(800, 800), "game");
		}

		void lost(void){
			sf::Font font;
			if(!font.loadFromFile("/mnt/c/Users/Victoria/Documents/projects/snake/include/Sqaurewave.ttf")){
				cout << "wellp\n";
			}

			sf::Text text1;
			sf::Text text2;
			sf::Text text3;

			text1.setFont(font);
			text2.setFont(font);
			text3.setFont(font);

			text1.setString("YOU LOST");
			text2.setString("PRESS R TO RESTART");
			text3.setString("PRESS Q TO QUIT");

			window.draw(text1);
			window.draw(text2);
			window.draw(text3);
		}

		void drawGame(void){
			for(int i=0; i<snek.sn.size(); i++){
				window.draw(snek.sn[i]);
			}
			window.draw(fod.f);
		}

		void input(sf:: Event event){

			switch(event.key.code){
				case sf::Keyboard::Left:	
					dir=LEFT;
					break;
				
				case sf::Keyboard::Right:
					dir=RIGHT;
					break;
			
				case sf::Keyboard::Up:
					dir=UP;
					break;
			
				case sf::Keyboard::Down:
					dir=DOWN;
					break;
				}

			snek.move(dir);
		}

		bool eat(void){
			bool a= false;
			if(snek.pos() == fod.pos())
				a = true;
			return a;
		}

		void update(const sf::Vector2f& pos){
			fod.update();
			snek.grow(pos);
		}


		bool headpos(void){
			// bool a=false;
			if (snek.sn.front().getPosition().x < 0 || snek.sn.front().getPosition().x > 800) 
				return true;
			if (snek.sn.front().getPosition().y < 0 || snek.sn.front().getPosition().y > 800) 
				return true;
			
			return false;
		}

		void gameLoop(void){

			sf::Clock clock;
			// window.setFramerateLimit(4);

			while (window.isOpen()){
				// check all the window's events that were triggered since the last iteration of the loop
				sf::Event event;
				while (window.pollEvent(event)){
					// "close requested" event: we close the window
					// if (event.type == sf::Event::Closed)
					// 	window.close();

					if (event.type == sf::Event::Closed)
						window.close();

					if(event.type == sf::Event::KeyPressed){
						input(event);
						clock.restart();
					}

				}

				// clear the window with black color
				window.clear(sf::Color::Black);
				if(eat())
					update(fod.pos());

				// draw everything here...
				// window.draw(...);
				sf::Time time = clock.getElapsedTime();
				// clock.getElapsedTime();
				if(time.asSeconds() > 0.4){
					snek.move(dir);
					clock.restart();
					// if(headpos())
					// 	lost();
					
				}	
				drawGame();

				// end the current frame
				window.display();
			}
		}
};

