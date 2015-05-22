#include "src/headers/hadouken_fsm.h"

namespace open_hadouken {

hadouken::waiting_state* hadouken::waiting_state::_instance = nullptr;
hadouken::down_state* hadouken::down_state::_instance = nullptr;
hadouken::quarter_cycle_state* hadouken::quarter_cycle_state::_instance = nullptr;
hadouken::front_state* hadouken::front_state::_instance = nullptr;
hadouken::final_state* hadouken::final_state::_instance = nullptr;

hadouken::fsm::fsm():  _state(waiting_state::instance())
{
}

hadouken::fsm::~fsm()
{
}

bool hadouken::fsm::input(const key_pressed &key)
{
    _state = _state->input(key);
    if(_state == final_state::instance())
    {
        _state = waiting_state::instance();
        return true;
    }
    return false;
}

const hadouken::state *hadouken::waiting_state::input(const key_pressed &key) const
{
    const hadouken::state* result = waiting_state::instance();
    if(key.key() == sf::Keyboard::S && key.down())
        result = down_state::instance();
    return result;
}

const hadouken::state *hadouken::down_state::input(const key_pressed &key) const
{
    const hadouken::state* result = waiting_state::instance();
    if(key.key() == sf::Keyboard::D && key.down())
        result = quarter_cycle_state::instance();
    return result;
}

const hadouken::state *hadouken::quarter_cycle_state::input(const key_pressed &key) const
{
    const hadouken::state* result = waiting_state::instance();
    if(key.key() == sf::Keyboard::S && !key.down())
        result = front_state::instance();
    return result;
}

const hadouken::state *hadouken::front_state::input(const key_pressed &key) const
{
    const hadouken::state* result = waiting_state::instance();
    if(key.key() == sf::Keyboard::K && key.down())
        result = final_state::instance();
    return result;
}

const hadouken::state *hadouken::final_state::input(const key_pressed &key) const
{
    return waiting_state::instance();
}

}
