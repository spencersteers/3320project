// Author: Spencer Steers
// Date:   05.07.2013
// File:   weapon.h
// Definition of class weapon; contains damage, name, and hit chance


#ifndef __3320project__weapon__
#define __3320project__weapon__

#include <string>
#include "rng.h"

class weapon
{
public:
    weapon() {};
    weapon(std::string n, int d, int hc);

    /* Getters */
    std::string get_name();
    int get_damage();
    int get_hit_chance();

    /* Factory Methods */
    
    // Pre: None
    // Post: Returns either a sword, axe, or spear
    static weapon create_random_player_weapon();
    
    // Pre: None
    // Post: Returns either a troth, geff, or beff
    static weapon create_random_enemy_weapon();
    

private:
    std::string name;
    int damage;
    int hit_chance;
};



#endif
