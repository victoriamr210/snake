#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class food{

  public:
		sf::RectangleShape f;
    int x;
    int y;

    food(){
      this->f.setSize(sf::Vector2f(100, 100));
      this->f.setPosition(500, 500);
    }
};