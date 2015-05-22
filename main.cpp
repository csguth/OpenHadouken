#include <iostream>

#include <SFML/Graphics.hpp>
#include "src/headers/game.h"
#include "src/headers/keyboard.h"
#include "src/headers/hadouken.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hadouken :) by csguth");
    open_hadouken::keyboard keyboard;
    open_hadouken::hadouken_fsm hadouken;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased)
            {
                if(hadouken.input(keyboard.event(event)))
                    std::cout << "HADOUKEN!!" << std::endl;
            }

        }
        open_hadouken::game::update();
        open_hadouken::game::render(window);
    }

    return 0;
}

