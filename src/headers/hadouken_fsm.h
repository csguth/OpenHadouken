#ifndef HADOUKEN_H
#define HADOUKEN_H

#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Clock.hpp>
#include "keyboard.h"

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

    bool input(const key_pressed &key);
};

}

#endif // HADOUKEN_H
