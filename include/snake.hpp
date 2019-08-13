#include <iostream>
#include <vector>
#include "food.hpp"
#include "things.hpp"
#include <utility>
#include <SFML/Graphics.hpp>
using namespace std;

// class snake{

// 	public:
// 		int headX;
// 		int headY;
// 		int tailX[50];
// 		int tailY[50];
	
// 	public:
// 		snake(){
// 			headX = rand() % 30;
// 			headY = rand() % 20;
// 			cout << headX << " " << headY << endl;
// 		}
// };


class snake{

	public:
		int headX;
		int headY;
		int tailX[50];
		int tailY[50];
		enum direction moving=STOP;

	public:
		vector<sf::RectangleShape> sn;
		vector<direction> moves;
		// (sf::Vector2f(120.f, 50.f));

		snake(){
			sf::RectangleShape ss;
			direction aux=STOP;
			ss.setSize(sf::Vector2f(100, 100));
			ss.setPosition(100,100);
			ss.setFillColor(sf::Color(100, 250, 50));
			ss.setOutlineColor(sf::Color::Blue);
			ss.setOutlineThickness(2);

						sn.push_back(ss);
			moves.push_back(aux);


		}

		const sf::Vector2f & pos (void){
			return sn.front().getPosition();
		}

		void move(enum direction dir){
			if(dir == STOP){
				return;
			}else{
				int x = sn.back().getPosition().x;
				int y = sn.back().getPosition().y;
				direction aux=moving;

				switch(dir){
					case LEFT:
						if( sn.size()>1 && aux!=RIGHT ){
							sn.front().move(-100.f,0.f);					
							moving = LEFT;
						}else{
							sn.front().move(-100.f, 0.f);
							moving = LEFT;
						}
						break;
					
					case RIGHT:
						if(sn.size()>1 && aux!=LEFT){
							sn.front().move(100.f, 0.f);
							moving = RIGHT;
						}else{
							sn.front().move(100.f, 0.f);
							moving = RIGHT;
						}
						break;
					
					case UP:
						if( sn.size()>1 && aux!=DOWN){
							sn.front().move(0.f, -100.f);
							moving = UP;
						}else{
							sn.front().move(0.f, -100.f);
							moving = UP;
						}
						break;
					
					case DOWN:
						if(sn.size()>1 && aux!=UP){
							sn.front().move(0.f, 100.f);
							moving = DOWN;
						}else{
							sn.front().move(0.f, 100.f);
							moving = DOWN;
						}
						break;
				}

				if(sn.size()>1) move_tail(x,y);
				moves[0]=dir;
			}	
		}

		void move_tail(int x, int y){
			direction aux;
			for(int i=1; i< sn.size(); i++){
				aux = moves[i-1];
				switch(aux){
					case LEFT:
						sn[i].move(-100.f, 0.f);
						break;
					case RIGHT:
						sn[i].move(100.f, 0.f);
						break;
					case UP:
						sn[i].move(0.f, -100.f);
						break;
					case DOWN:
						sn[i].move(0.f, 100.f);
						break;
				}
			}
			for(int i= sn.size()-1; i>0; i--){
				moves[i]= moves[i-1];
			}
			
		}

		void grow(const sf::Vector2f& pos){
			enum direction aux;
			aux=moving;
			sf::RectangleShape ss;
			ss.setSize(sf::Vector2f(100, 100));

			int x = sn.back().getPosition().x;
			int y = sn.back().getPosition().y;
			// ss.setPosition(100, 100);
			ss.setFillColor(sf::Color(100, 250, 50));
			ss.setOutlineColor(sf::Color::Blue);
			ss.setOutlineThickness(2);

			// sn.push_back(ss);
			// while(pos != sn.back().getPosition())
			// 	move(moving);

			// ss.setPosition(100, 100);
			sn.push_back(ss);
			moves.push_back(moves[moves.size()-1]);
			switch(moves.back()){
				case LEFT:
					sn.back().setPosition(x+100, y);
					break;
				case RIGHT:
					sn.back().setPosition(x-100, y);
					break;
				case UP:
					sn.back().setPosition(x,y+100);
					break;
				case DOWN:
					sn.back().setPosition(x, y-100);
			}	

		}

		

		// snake()
		// {
		// 	headX = rand() % 30;
		// 	headY = rand() % 20;
		// 	cout << headX << " " << headY << endl;
		// }
};
