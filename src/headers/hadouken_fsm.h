#ifndef HADOUKEN_H
#define HADOUKEN_H

#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Clock.hpp>
#include "keyboard.h"
#include <iostream>
#include <memory>

namespace open_hadouken {

namespace hadouken {
class state
{
public:
    virtual const state* input(const key_pressed &key) const = 0;
};

class waiting_state : public state
{
    waiting_state(){}
    static waiting_state* _instance;
public:
    static const state * instance() {
        if(waiting_state::_instance == nullptr)
            waiting_state::_instance = new waiting_state;
        return waiting_state::_instance;
    }
    const state* input(const key_pressed &key) const;
};
class down_state : public state
{
    static down_state* _instance;
public:
    static const state * instance() {
        if(down_state::_instance == nullptr)
            down_state::_instance = new down_state;
        return down_state::_instance;
    }
    const state* input(const key_pressed &key) const;
};

class quarter_cycle_state : public state
{
    static quarter_cycle_state* _instance;
public:
    static const state * instance() {
        if(quarter_cycle_state::_instance == nullptr)
            quarter_cycle_state::_instance = new quarter_cycle_state;
        return quarter_cycle_state::_instance;
    }
    const state* input(const key_pressed &key) const;
};

class front_state : public state
{
    static front_state* _instance;
public:
    static const state * instance() {
        if(front_state::_instance == nullptr)
            front_state::_instance = new front_state;
        return front_state::_instance;
    }
    const state* input(const key_pressed &key) const;
};

class final_state : public state
{
    static final_state* _instance;
public:
    static const final_state * instance() {
        if(final_state::_instance == nullptr)
            final_state::_instance = new final_state;
        return final_state::_instance;
    }
    const state* input(const key_pressed &key) const;
};

class fsm
{
    const state *_state;
public:

    fsm();
    ~fsm();
    bool input(const key_pressed &key);
};
}

}

#endif // HADOUKEN_H
