// Author: Spencer Steers
// Date:   05.07.2013
// File:   main.cpp
// 

#include <string>
#include <iostream>
#include "weapon.h"
#include "actor.h"
#include "rng.h"
#include "room.h"


void initialize_rooms()
{
    weapon w = weapon::create_random_player_weapon();
    std::cout << w.get_name() << " " << w.get_damage() << " " << w.get_hit_chance();
    std::cout << std::endl;
    
    actor player = actor::create_player();
    
    std::cout << player.get_name() << " " << player.get_weapon_damage() << " " << player.get_max_health();
    
    weapon pw = player.get_equipped_weapon();
    std::cout << pw.get_name();
    
    room gr("Guard Room", player);
    room cy("Court Yard", player);
    
    gr.add_connection(cy.get_name());
    
    std::cout << gr.get_connections()[0];
    
    

}


int main(int argc, char const *argv[])
{
    
    initialize_rooms();
    return 0;
}