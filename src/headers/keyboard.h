#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <utility>

namespace open_hadouken {

class key_pressed
{
    sf::Keyboard::Key _key;
    bool _up;
public:
    key_pressed(sf::Keyboard::Key key, bool up);
    sf::Keyboard::Key key() const { return _key; }
};

enum class key {
    UP = 0, RIGHT, DOWN, LEFT
};

class keyboard
{
public:
    keyboard();
    std::pair<sf::Keyboard::Key, bool> event(const sf::Event &event);
};

}

#endif // KEYBOARD_H
