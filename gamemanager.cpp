// Author: Spencer Steers
// Date:   05.08.2013
// File:   gamemanager.cpp
// Implementation of class gamemanager

#include "gamemanager.h"

gamemanager::gamemanager():player(actor::create_player())
{
    initialize_rooms();
    current_room = &(rooms["Guard Room"]);
    treasure_count = 0;
}

void gamemanager::start_game()
{
    // Clear screen and greet
    //system("clear");
    //std::cout << std::string( 100, '\n' );
    std::cout << std::endl;
    std::cout << "Hail! And Welcome to the evil castle!" << std::endl;
    std::cout << "Please consult the readme for information" << std::endl;
    std::cout << "on how the project and code is structured" << std::endl;
    std::cout << "May your swords stay sharp, and your spells fast!" << std::endl;

    char c;
    std::cout << "Press any key followed by ENTER -> ";
    std::cin >> c;
    std::cout << std::endl;
    std::cout << std::endl;

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
            print_newline(player.get_name() + " enters the " + current_room->get_name());
        
            if (current_room->is_clear())
                current_state = go_to_room;
            else
                current_state = is_battle;
        }
        else if (current_state == is_battle)
        {
            bool result = battle();
            if (result)
            {
                treasure_count += room::TREASURE_VALUE;
                current_state = after_battle_victory;

                print_line(current_room->get_enemy().get_name() + " was defeated for ");
                print_line(room::TREASURE_VALUE);
                print_newline(" gold!");
                print_line("You have ");
                print_line(treasure_count);
                print_newline(" gold!");
                print_newline("");
            }
            else
            {
                current_state = game_over;

                print_newline(player.get_name() + " was defeated.");
                print_newline("You lose!");
            }
        }
        else if (current_state == after_battle_victory)
        {
            if (treasure_count >= 500)
            {
                current_state = game_over; 

                print_newline("**** Congratulations ****");
                print_newline("You have found all the treasure and defeated the evil within the castle!");
            }
            else
                current_state = go_to_room;
        }
        else if (current_state == go_to_room)
        {
            /* display */
            print_newline(player.get_name() + " stands in the empty " + current_room->get_name());
            print_newline("Where do you want to go? ");
            std::vector<std::string> conn = current_room->get_connections();
            int count = 0;
            for (std::vector<std::string>::iterator i = conn.begin(); i != conn.end(); ++i)
            {
                ++count;
                print_line(count);
                print_newline(" " + *i);
            }
            /* end display */

            // So the computer doesn't continuously walk in cleared rooms
            int random_input = smart_random_room();
            // Sleep to pretend getting input
            usleep(LONG_SLEEP_TIME);
            print_line(random_input + 1);
            print_newline("");

            // If the selected direction is a room continue loop
            try 
            {
                current_room = &rooms.at(conn[random_input]);
                current_state = new_room;
            }
            // If not try again
            catch (std::exception& e)
            {
                current_state = go_to_room;
                print_newline("Can't go there!");
            }

            print_newline("");
        }

        usleep(STATE_SLEEP_TIME);
    }
}

bool gamemanager::battle()
{
    /* display */
    print_newline("A " + current_room->get_enemy().get_name() + 
            " defends the " + current_room->get_name() + " and a large pile of treasure!");
    
    weapon e_wep = current_room->get_enemy().get_equipped_weapon();
    weapon p_wep = player.get_equipped_weapon();

    print_line("Angered by your presence the " + current_room->get_enemy().get_name() +" charges at the " + player.get_name());
    print_line(" with a " + e_wep.get_name());
    std::cout << " (" << e_wep.get_damage() << " damage, %" << e_wep.get_hit_chance() << " hit chance)" << std::endl;
    usleep(SHORT_SLEEP_TIME);
    std::cout << player.get_name() << " readies his " << p_wep.get_name();
    std::cout <<" (" << p_wep.get_damage() << " damage, %" << p_wep.get_hit_chance() << " hit chance)" << std::endl;
    print_newline("Battle ensues!");
    print_newline("");
    /* display */


    actor* first;
    actor* second;

    // check who goes first
    if (rng::get_instance().probability(50))
    {
        first = &player;
        second = &current_room->get_enemy();
    }
    else
    {
        first = &current_room->get_enemy();
        second = &player;
    }

    bool in_battle = true;
    bool first_turn = true;
    while (in_battle)
    {
        if (first_turn)
        {
            battle_turn(first, second);
        }
        else
        {
            battle_turn(second, first);
        }

        // Flip to next turns
        first_turn = !first_turn;
        if (first->is_dead() || second->is_dead())
            in_battle = false;
    }
    print_newline("");
    return !player.is_dead();
}

void gamemanager::battle_turn(actor* attacker, actor* defender)
{
    bool hit = attacker->will_hit();
    int damage = 0;
    if (hit)
    {
       damage = attacker->get_weapon_damage();
       defender->take_damage(damage);
    }

    display_battle_turn(hit, damage, attacker, defender);
}

int gamemanager::smart_random_room()
{
    if (current_room->get_name() == "Court Yard" && rooms["Art Room"].is_clear())
    {
        return 2;
    }
    else if (current_room->get_name() == "Court Yard" && rooms["Great Hall"].is_clear())
    {
        return 0;
    }
    else if (current_room->get_name() == "Great Hall" && rooms["Art Room"].is_clear())
    {
        return 0;
    }
    else if (current_room->get_name() == "Great Hall" && rooms["Dungeon"].is_clear())
    {
        return 1;
    }
    else
    {
        return rng::get_instance().range(current_room->get_connections().size());
    }
}

void gamemanager::initialize_rooms()
{
    // Create rooms and enemies
    room gr("Guard Room", actor::create_random_enemy());
    room cy("Court Yard", actor::create_random_enemy());
    room ar("Art Room", actor::create_random_enemy());
    room gh("Great Hall", actor::create_random_enemy());
    room d("Dungeon", actor::create_random_enemy());

    gr.add_connection(cy.get_name());

    cy.add_connection(ar.get_name());
    cy.add_connection(gr.get_name());
    cy.add_connection(gh.get_name());

    ar.add_connection(cy.get_name());

    gh.add_connection(d.get_name());
    gh.add_connection(cy.get_name());

    d.add_connection(gh.get_name());

    rooms.insert(std::pair<std::string, room>(gr.get_name(), gr));
    rooms.insert(std::pair<std::string, room>(cy.get_name(), cy));
    rooms.insert(std::pair<std::string, room>(ar.get_name(), ar));
    rooms.insert(std::pair<std::string, room>(gh.get_name(), gh));
    rooms.insert(std::pair<std::string, room>(d.get_name(), d));
}

void gamemanager::display_battle_turn(bool did_hit, int damage, actor* attacker, actor* defender)
{
    print_newline(attacker->get_name() + " swings his " + attacker->get_equipped_weapon().get_name());
    usleep(COMBAT_SLEEP_TIME);
    if (did_hit)
    {
        std::cout << attacker->get_name() << " hits for " << damage << " damage ";
        std::cout << defender->get_name() << ": (" << defender->get_current_health() << "/" << defender->get_max_health();
        std::cout << ") hp remianing" << std::endl;
    }
    else
    {
        std::cout << attacker->get_name() << " misses ";
        std::cout << defender->get_name() << ": (" << defender->get_current_health() << "/" << defender->get_max_health();
        std::cout << ") hp remianing" << std::endl;
    }
    std::cout << std::endl;
    usleep(STATE_SLEEP_TIME);
}


void gamemanager::print_newline(std::string text)
{
    std::cout << text << std::endl;
}

void gamemanager::print_line(std::string text)
{
    std::cout << text;
}

void gamemanager::print_line(int val)
{
    std::cout << val;
}
