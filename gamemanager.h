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
#include <iomanip>
#include <cstdlib>
#include <exception>
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

/*    Uncomment for faster game 
    static const int STATE_SLEEP_TIME = 100000;
    static const int COMBAT_SLEEP_TIME = 100000;
    static const int SHORT_SLEEP_TIME = 75000;
    static const int LONG_SLEEP_TIME = 100000;
*/  
    static const int STATE_SLEEP_TIME = 1000000;
    static const int COMBAT_SLEEP_TIME = 1500000;
    static const int SHORT_SLEEP_TIME = 750000;
    static const int LONG_SLEEP_TIME = 2000000;

    // The 5 states of the game
    // The current state is stored in.. current_state
    enum gamestate 
    {
        new_room = 0,
        is_battle,
        after_battle_victory,
        go_to_room,
        game_over,
    };

    std::map<std::string, room> rooms;
    actor player;
    room* current_room;
    gamestate current_state;
    int treasure_count;

    /* Private Functions */

    // Finite state machine for game
    void main_loop();

    // Returns false if the player dies, true if not
    bool battle();

    // Executes one turn of the battle
    void battle_turn(actor* attacker, actor* defender);
    
    // Prevents wandering around the castle
    int smart_random_room();

    // Sets up structure of rooms according to doc
    void initialize_rooms();

    /* Display functions */
    void display_battle_turn(bool did_hit, int damage, actor* attacker, actor* defender);
    void print_newline(std::string text);
    void print_line(std::string text);
    void print_line(int val);

};

#endif