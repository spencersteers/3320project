// Author: Spencer Steers
// Date:   05.07.2013
// File:   room.cpp
// Implementation of class room

#include "room.h"

void room::add_connection(std:string room_name)
{
    if (find(connected_rooms.begin(), connected_rooms.end(), room_name) 
                                                != connected_rooms.end())
    {
        connected_rooms.push_back(room_name);
    }
}


const std::vector<std::string>& get_connections()
{
    return connected_rooms;
}

bool room::is_clear()
{
    if (enemy.is_dead())
        return true;
}