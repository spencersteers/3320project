// Author: Spencer Steers
// Date:   05.08.2013
// File:   gamemanager.cpp
// Implementation of class gamemanager

#include "gamemanager.h"

gamemanager::gamemanager():player(actor::create_player())
{
    initialize_rooms();
    //player = actor::create_player();
    current_room = &(rooms["Guard Room"]);
    treasure_count = 0;
}

void gamemanager::start_game()
{
    current_state = new_room;
    main_loop();
}

void gamemanager::main_loop()
{
    // Main loop that runs till game_over
    while(current_state != game_over)
    {
        if (current_state == new_room)
        {
            print_line("You have entered the " + current_room->get_name());
        
            if (current_room->is_clear())
                current_state = go_to_room;
            else
                current_state = is_battle;
        }
        else if (current_state == is_battle)
        {
            bool result = battle();
            if (result)
                current_state = go_to_room;
            else
            {
                // defeat
            }
        }
        else if (current_state == go_to_room)
        {
            // pick new room
        }
    }
}

void gamemanager::battle()
{

}

void gamemanager::initialize_rooms()
{
    // Create rooms and enemies
    room gr("Guard Room", actor::create_random_enemy());
    room cy("Court Yard", actor::create_random_enemy());
    room ar("Art Room", actor::create_random_enemy());
    room gh("Great Hall", actor::create_random_enemy());
    room d("Dungeon", actor::create_random_enemy());

    // Create room connections
    // [0] north, [1] south, [2] east, [3] west
    gr.add_connection(cy.get_name());
    //gr.add_connection("Castle Entrance (You can't leave yet!)");
    //gr.add_connection("Wall");
    //gr.add_connection("West");

    cy.add_connection(ar.get_name());
    cy.add_connection(gr.get_name());
    //
    cy.add_connection(gh.get_name());

    //
    ar.add_connection(cy.get_name());
    //
    //

    //
    gh.add_connection(d.get_name());
    //
    gh.add_connection(cy.get_name());
    //

    d.add_connection(gh.get_name());
    //
    //
    //

    rooms.insert(std::pair<std::string, room>(gr.get_name(), gr));
    rooms.insert(std::pair<std::string, room>(cy.get_name(), cy));
    rooms.insert(std::pair<std::string, room>(ar.get_name(), ar));
    rooms.insert(std::pair<std::string, room>(gh.get_name(), gh));
    rooms.insert(std::pair<std::string, room>(d.get_name(), d));
}

void gamemanager::print_line(std::string text)
{
    std::cout << text << std::endl;
}