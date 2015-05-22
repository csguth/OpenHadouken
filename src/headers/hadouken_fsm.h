#ifndef HADOUKEN_H
#define HADOUKEN_H

#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Clock.hpp>
#include "keyboard.h"
#include <iostream>

namespace open_hadouken {

namespace hadouken {
class state
{
public:
    static state* WAITING;
    static state* DOWN;
    static state* QUARTER_CYCLE;
    static state* FRONT;
    static state* FINAL;
    virtual state* input(const key_pressed &key) = 0;
};

class waiting_state : public state
{
public:
    state* input(const key_pressed &key);
};
class down_state : public state
{
public:
    state* input(const key_pressed &key);
};

class quarter_cycle_state : public state
{
public:
    state* input(const key_pressed &key);
};

class front_state : public state
{
public:
    state* input(const key_pressed &key);
};

class final_state : public state
{
public:
    state* input(const key_pressed &key);
};



class fsm
{
    state *_state;

public:

    fsm();
    ~fsm();

    bool input(const key_pressed &key);
};
}

}

#endif // HADOUKEN_H
