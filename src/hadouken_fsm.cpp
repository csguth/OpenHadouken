#include "src/headers/hadouken_fsm.h"

namespace open_hadouken {

hadouken::state* hadouken::state::state::WAITING = new hadouken::waiting_state;
hadouken::state* hadouken::state::state::DOWN = new hadouken::down_state;
hadouken::state* hadouken::state::state::QUARTER_CYCLE = new hadouken::quarter_cycle_state;
hadouken::state* hadouken::state::state::FRONT = new hadouken::front_state;
hadouken::state* hadouken::state::state::FINAL = new hadouken::final_state;

hadouken::fsm::fsm():  _state(state::WAITING)
{

}

hadouken::fsm::~fsm()
{

}

bool hadouken::fsm::input(const key_pressed &key)
{
    _state = _state->input(key);
    if(_state == state::FINAL)
    {
        _state = state::WAITING;
        return true;
    }
    return false;
}

hadouken::state *hadouken::waiting_state::input(const key_pressed &key)
{
    hadouken::state* result = hadouken::state::WAITING;
    if(key.key() == sf::Keyboard::S && key.down())
        result = hadouken::state::DOWN;
    return result;
}

hadouken::state *hadouken::down_state::input(const key_pressed &key)
{
    hadouken::state* result = hadouken::state::WAITING;
    if(key.key() == sf::Keyboard::D && key.down())
        result = hadouken::state::QUARTER_CYCLE;
    return result;
}

hadouken::state *hadouken::quarter_cycle_state::input(const key_pressed &key)
{
    hadouken::state* result = hadouken::state::WAITING;
    if(key.key() == sf::Keyboard::S && !key.down())
        result = hadouken::state::FRONT;
    return result;
}

hadouken::state *hadouken::front_state::input(const key_pressed &key)
{
    hadouken::state* result = hadouken::state::WAITING;
    if(key.key() == sf::Keyboard::K && key.down())
        result = hadouken::state::FINAL;
    return result;
}

hadouken::state *hadouken::final_state::input(const key_pressed &key)
{
    return hadouken::state::WAITING;
}

}
