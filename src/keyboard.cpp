#include "src/headers/keyboard.h"

namespace open_hadouken {

keyboard::keyboard()
{
}

key_pressed keyboard::event(const sf::Event &event)
{
    bool key_down = event.type == sf::Event::KeyPressed;
    bool key_up = event.type == sf::Event::KeyReleased;
    if(key_down || key_up)
        return key_pressed{event.key.code, key_down};
    return key_pressed{sf::Keyboard::Unknown, key_down};
}

key_pressed::key_pressed(sf::Keyboard::Key key, bool down) : _key(key), _down(down)
{

}



}
