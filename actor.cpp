// Author: Spencer Steers
// Date:   05.07.2013
// File:   actor.cpp
// Implementation of class actor

#include "actor.h"

actor::actor(std::string n, weapon& w, int mh):name(n),
                                               equiped_weapon(w),
                                               max_health(mh)
{
    current_health = max_health;
}


bool actor::is_dead() { return current_health <= 0; }

void actor::take_damage(int dam) { current_health -= dam; }



std::string actor::get_name() { return name; }

int actor::get_current_health() { return current_health; }

int actor::get_max_health() { return max_health; }
