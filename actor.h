// Author: Spencer Steers
// Date:   05.07.2013
// File:   actor.h
// Declaration of class actor, represents a room in the game
// with a monster, treasure, and locations
        
#ifndef __3320project__actor__
#define __3320project__actor__


#include <string>
#include "weapon.h"
#include "rng.h"

class actor
{
public:
    actor() {};
    actor(std::string n, weapon w, int mh);

    // Pre: None
    // Post: returns true if current_health < 0
    bool is_dead();

    // Pre: None
    // Post: Reduces current health by dam
    void take_damage(int dam);

    // Pre: An equipped weapon
    // Post: Returns true if weapon will hit
    bool will_hit();

    // Pre: An equipped weapon
    // Post: Damage the weapon will do
    int get_weapon_damage();

    /* Getters */
    std::string get_name();
    int get_current_health();
    int get_max_health();
    const weapon& get_equipped_weapon();

    /* Factory Functions */
    
    // Pre: None
    // Post: An initialized actor to the player spec
    static actor create_player();
    
    // Pre: None
    // Post: An initialized actor that is one of three random enemies
    static actor create_random_enemy();
    

private:
    std::string name;
    weapon equipped_weapon;
    int max_health;
    int current_health;
};

#endif
