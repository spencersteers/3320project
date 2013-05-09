// Author: Spencer Steers
// Date:   05.08.2013
// File:   gamemanager.h
// Definition of class gamemanager
// Manages the game lifecycle and loop
// responsible for initializing all other classes and serves
// as the driver for the project 


#ifndef __3320project__gamemanager__
#define __3320project__gamemanager__

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "weapon.h"
#include "actor.h"
#include "rng.h"
#include "room.h"

class gamemanager
{
public:
    gamemanager();

    // Pre: None
    // Post: Starts the main game loop
    void start_game();

private:


    enum gamestate 
    {
        new_room = 0,
        is_battle,
        go_to_room,
        game_over,
    };

    std::map<std::string, room> rooms;
    actor player;
    room* current_room;
    gamestate current_state;
    int treasure_count;

    void main_loop();
    bool battle();
    void initialize_rooms();
    void print_line(std::string text);
};

#endif