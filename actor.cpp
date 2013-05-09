// Author: Spencer Steers
// Date:   05.07.2013
// File:   actor.cpp
// Implementation of class actor

#include "actor.h"

actor::actor(std::string n, weapon w, int mh):name(n),
                                               equipped_weapon(w),
                                               max_health(mh),
                                               current_health(mh) {};

bool actor::is_dead() { return current_health <= 0; }

void actor::take_damage(int dam) { current_health -= dam; }

std::string actor::get_name() { return name; }

int actor::get_current_health() { return current_health; }

int actor::get_max_health() { return max_health; }

bool actor::will_hit() 
{ 
    return rng::get_instance().probability(equipped_weapon.get_hit_chance());
}

int actor::get_weapon_damage() { return equipped_weapon.get_damage(); }

weapon actor::get_equipped_weapon() { return equipped_weapon; }

actor actor::create_player()
{
    actor p("Player", weapon::create_random_player_weapon(), 50);
    return p;
}

actor actor::create_random_enemy()
{
    int enemy_to_create = rng::get_instance().range(3);
    
    // Troll
    if (enemy_to_create == 0)
    {
        actor e("Troll", weapon::create_random_enemy_weapon(), 13);
        return e;
    }
    // Gelfling
    else if (enemy_to_create == 1)
    {
        actor e("Gelfling", weapon::create_random_enemy_weapon(), 6);
        return e;
    }
    // Belf
    else
    {
        actor e("Belf", weapon::create_random_enemy_weapon(), 7);
        return e;
    }
}