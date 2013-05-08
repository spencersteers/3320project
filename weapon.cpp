// Author: Spencer Steers
// Date:   05.07.2013
// File:   weapon.cpp
// Implementation of class weapon

#include "weapon.h"

weapon::weapon(std::string n, int d, int hc):name(n), damage(d), hit_chance(hc) {}

std::string weapon::get_name() { return name; }

int weapon::get_damage() { return damage; }

int weapon::get_hit_chance() { return hit_chance; }


weapon weapon::create_random_player_weapon()
{
    int weapon_to_create = rng::get_instance().range(3);
    
    // Sword
    if (weapon_to_create == 0)
    {
        weapon w("Sword", 5, 40);
        return w;
    }
    // Axe
    else if (weapon_to_create == 1)
    {
        weapon w("Axe", 4, 50);
        return w;
    }
    // Spear
    else
    {
        weapon w("Spear", 3, 60);
        return w;
    }
}

weapon weapon::create_random_enemy_weapon()
{
    int weapon_to_create = rng::get_instance().range(3);
    
    // Troth
    if (weapon_to_create == 0)
    {
        weapon w("Troth", 5, 50);
        return w;
    }
    // Geff
    else if (weapon_to_create == 1)
    {
        weapon w("Geff", 4, 20);
        return w;
    }
    // Beff
    else
    {
        weapon w("Beff", 3, 35);
        return w;
    }
}