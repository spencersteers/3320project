// Author: Spencer Steers
// Date:   05.07.2013
// File:   room.h
// Definition of class room which represents a room in the
// games castle

#ifndef __3320project__room__
#define __3320project__room__

#include <string>
#include <vector>
#include <algorithm>
#include "actor.h"

class room
{
public:

    // Pre: None
    // Post: adds a room name as a connection
    void add_connection(std::string room_name);

    // Pre: None
    // Post: returns a vector of room names the instance is
    //       connected to
    const std::vector<std::string>& get_connections();

    // Pre: None
    // Post: Checks if there is anything left to do in the room    
    bool is_clear();



    /**** Getters ****/
    actor& get_enemy();

private:
    std::string name;
    std::vector<std::string> connected_rooms;
    actor enemy;
    static const int TREASURE_VALUE = 100;
};

#endif
