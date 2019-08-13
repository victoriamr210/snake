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
		direction dir;
		// sf::RectangleShape snake(sf::Vector2f(120.f, 50.f));
		// sf::RectangleShape food(sf::Vector2f(120.f, 50.f));

		game(){
			this->window.create(sf::VideoMode(800, 600), "game");
		}

		void drawGame(void){
			window.draw(snek.ss);
			window.draw(fod.f);
		}

		void input(void){
			sf::Event event;

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
				
				
				
				
				// if (event.key.code == sf::Keyboard::Left)
				// {
				// 	snake.move(-100.f, 0.f);
				// }
				// if (event.key.code == sf::Keyboard::Right)
				// {
				// 	snake.move(100.f, 0.f);
				// }
				// if (event.key.code == sf::Keyboard::Up)
				// {
				// 	snake.move(0.f, -100.f);
				// }
				// if (event.key.code == sf::Keyboard::Down)
				// {
				// 	snake.move(0.f, 100.f);
				// }
				// break;
			}
		}

		void gameLoop(void){
			while (window.isOpen()){
				// check all the window's events that were triggered since the last iteration of the loop
				sf::Event event;
				while (window.pollEvent(event)){
					// "close requested" event: we close the window
					// if (event.type == sf::Event::Closed)
					// 	window.close();

					if (event.type == sf::Event::Closed)
						window.close();

					input();

				}

				// clear the window with black color
				window.clear(sf::Color::Black);

				// draw everything here...
				// window.draw(...);
				drawGame();

				// end the current frame
				window.display();
			}
		}
};

// enum Dir {LEFT, RIGHT, DOWN,UP, STOP};

// class game{

// 	public:
// 		snake snek;
// 		bool game_over;
// 		int height = 20;
// 		int width = 30;
// 		int fX;
// 		int fY;
// 		Dir d =STOP;
		
// 	public:

// 		game(){
// 			game_over = false;
// 			fX = rand() % 30;
// 			fY = rand() % 20;
// 		}	

// 		void setup(){

// 		}
// 		void board(){
// 				system("clear");

// 				for(int i =0; i<width; i++){
// 					cout << "#";
// 				}
// 				cout << endl;

// 				for(int i=0; i<height-1; i++){
// 					cout << "#";
// 					for (int j=0; j<width-2; j++){
// 							if(i == snek.headY && j == snek.headX)
// 								cout << "O";
// 							else{
// 								if(i == fY && j == fX)
// 								cout << "F";
// 							else
// 								cout << " ";
// 							}
// 					}
// 					cout  << "#" << endl;
// 				}

// 				for(int i =0; i<width; i++){
// 					cout << "#";
// 				}
// 				cout << endl;

// 			// game_over=true;
// 		}

// 		void draw(){
// 			board();


			

// 		}

// 		void logic(){
// 			switch(d){
// 				case UP:
// 					snek.headY--;
// 					break;

// 				case DOWN:
// 					snek.headY++;
// 					break;
				
// 				case RIGHT:
// 					snek.headX++;
// 					break;
				
// 				case LEFT:
// 					snek.headX--;
// 				break;

// 			}

// 			if(snek.headX < 0 || snek.headX >= width-2 || snek.headY < 0 || snek.headY >= height-2)
// 				game_over = true;

				
// 		}

// 		void input(){
// 			char key;
// 			 cin >> key;
// 			switch(key){
// 				case 'w':
// 					d=UP;
// 					break;
				
// 				case 'a':
// 					d=LEFT;
// 					break;
				
// 				case 's':
// 					d=DOWN;
// 					break;
				
// 				 case 'd':
// 				 	d=RIGHT;
// 				 	break;
// 			}


// 		}

// };

