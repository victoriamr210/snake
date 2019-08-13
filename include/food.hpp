#include <iostream>
#include <SFML/Graphics.hpp>
#include "things.hpp"
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

    const sf::Vector2f & pos(void){
      return f.getPosition();
    }

    void update(void){
      x = rand() % 7;
      y = rand() % 7;
      this->f.setPosition(positions[x], positions[y]);
    }
};