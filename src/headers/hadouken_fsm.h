#ifndef HADOUKEN_H
#define HADOUKEN_H

#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>

namespace open_hadouken {

class hadouken_fsm
{
    enum class state {
        WAITING, DOWN, QUARTER_CYCLE, FRONT
    };

    state _state;

public:

    hadouken_fsm();
    ~hadouken_fsm();

    bool input(const std::pair<sf::Keyboard::Key, bool> &key);
};

}

#endif // HADOUKEN_H
