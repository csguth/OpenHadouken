#include "src/headers/hadouken_fsm.h"

namespace open_hadouken {

hadouken_fsm::hadouken_fsm():  _state(state::WAITING)
{

}

hadouken_fsm::~hadouken_fsm()
{

}

bool hadouken_fsm::input(const std::pair<sf::Keyboard::Key, bool> &key)
{
    switch(_state)
    {
    case state::WAITING:
        _state = state::WAITING;
        if(key.first == sf::Keyboard::S && key.second)
            _state = state::DOWN;
        break;
    case state::DOWN:
        _state = state::WAITING;
        if(key.first == sf::Keyboard::D && key.second)
            _state = state::QUARTER_CYCLE;
        break;
    case state::QUARTER_CYCLE:
        _state = state::WAITING;
        if(key.first == sf::Keyboard::S && !key.second)
            _state = state::FRONT;
        break;
    case state::FRONT:
        _state = state::WAITING;
        if(key.first == sf::Keyboard::K && key.second)
            return true;
        break;
    }
    return false;
}

}
