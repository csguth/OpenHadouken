#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <utility>

namespace open_hadouken {

class key_pressed
{
    sf::Keyboard::Key _key;
    bool _down;
public:
    key_pressed(sf::Keyboard::Key key, bool down);
    sf::Keyboard::Key key() const { return _key; }
    bool down() const { return _down; }
};

enum class key {
    UP = 0, RIGHT, DOWN, LEFT
};

class keyboard
{
public:
    keyboard();
    key_pressed event(const sf::Event &event);
};

}

#endif // KEYBOARD_H
