#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

namespace open_hadouken
{

class game
{
public:
    static void update();
    static void render(sf::RenderWindow &window);
};

}

#endif // GAME_H
