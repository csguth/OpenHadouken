#include "src/headers/keyboard.h"

namespace open_hadouken {

key_pressed::key_pressed(sf::Keyboard::Key key, bool up) : _key(key), _up(up)
{

}

keyboard::keyboard()
{
}

std::pair<sf::Keyboard::Key, bool> keyboard::event(const sf::Event &event)
{
    bool key_down = event.type == sf::Event::KeyPressed;
    bool key_up = event.type == sf::Event::KeyReleased;
    if(key_down || key_up)
        return std::make_pair(event.key.code, key_down);
    return std::make_pair(sf::Keyboard::Unknown, key_down);
}


}
