// Author: Spencer Steers
// Date:   05.07.2013
// File:   weapon.cpp
// Implementation of class weapon

#include "weapon.h"

weapon::weapon():name(n), damage(d), hit_chance(hc) {};

std::string weapon::get_name() { return name };

int weapon::get_damage() { return damage; }

int weapon::get_hit_chance() { return hit_chance; }

bool will_hit() 
{ 
    return rng::get_instance().probability(equipped_weapon.get_hit_chance());
}

int get_weapon_damage()
{
    return equipped_weapon.get_damage();
}