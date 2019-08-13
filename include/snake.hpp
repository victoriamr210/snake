#include <iostream>
#include "food.hpp"
#include <SFML/Graphics.hpp>
using namespace std;

#include "things.hpp"
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

	public:
		sf::RectangleShape ss;
		// (sf::Vector2f(120.f, 50.f));

		snake(){
			srand(time(NULL));
			int x = rand() % 800;
			int y = rand() % 600;
			this->ss.setSize(sf::Vector2f(100, 100));
			this->ss.setPosition(100,100);
			this->ss.setFillColor(sf::Color(100, 250, 50));
		}

		void move(enum dir){

		}


		

		// snake()
		// {
		// 	headX = rand() % 30;
		// 	headY = rand() % 20;
		// 	cout << headX << " " << headY << endl;
		// }
};
