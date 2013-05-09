// Author: Spencer Steers
// Date:   05.07.2013
// File:   room.cpp
// Implementation of class room

#include "room.h"

room::room(std::string n, actor e):name(n), enemy(e) {}

void room::add_connection(std::string room_name) 
{ 
    connected_rooms.push_back(room_name); 
}

std::vector<std::string> room::get_connections() { return connected_rooms; }

bool room::is_clear() { return enemy.is_dead(); }

std::string room::get_name() { return name; }

actor& room::get_enemy() { return enemy; }
