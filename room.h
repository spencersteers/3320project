// Author: Spencer Steers
// Date:   05.07.2013
// File:   room.h
// Definition of class room which represents a room in the
// games castle

#ifndef __3320project__room__
#define __3320project__room__

#include <string>
#include <vector>
#include "actor.h"

class room
{
public:
    room() {};
    room(std::string n, actor e);

    // Pre: None
    // Post: adds a room name as a connection
    void add_connection(std::string room_name);

    // Pre: 4 strings corresponding to room names or obstacles (wall)
    // Post: The room wil then hold the connections to the other rooms
    void initalize_connections(std::string north, std::string south,
                                std::string east, std::string west);

    // Pre: None
    // Post: returns a vector of room names the instance is
    //       connected to
    std::vector<std::string> get_connections();

    // Pre: None
    // Post: Checks if there is anything left to do in the room    
    bool is_clear();


    /**** Getters ****/
    std::string get_name();
    actor& get_enemy();

    static const int TREASURE_VALUE = 100;

private:
    std::string name;
    std::vector<std::string> connected_rooms;
    actor enemy;
};

#endif
