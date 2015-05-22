#include "src/headers/hadouken_fsm.h"

namespace open_hadouken {

hadouken_fsm::hadouken_fsm():  _state(state::WAITING)
{

}

hadouken_fsm::~hadouken_fsm()
{

}

bool hadouken_fsm::input(const key_pressed &key)
{
    switch(_state)
    {
    case state::WAITING:
        _state = state::WAITING;
        if(key.key() == sf::Keyboard::S && key.down())
            _state = state::DOWN;
        break;
    case state::DOWN:
        _state = state::WAITING;
        if(key.key() == sf::Keyboard::D && key.down())
            _state = state::QUARTER_CYCLE;
        break;
    case state::QUARTER_CYCLE:
        _state = state::WAITING;
        if(key.key() == sf::Keyboard::S && !key.down())
            _state = state::FRONT;
        break;
    case state::FRONT:
        _state = state::WAITING;
        if(key.key() == sf::Keyboard::K && key.down())
            return true;
        break;
    }
    return false;
}

}
