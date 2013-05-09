// Author: Spencer Steers
// Date:   05.07.2013
// File:   main.cpp
// This is int main for the 3320 project
// it is only responsible for initializing and
// calling start_game() on an instance of gamemanager
// the rest of the game takes place 
// inside gamemanage.main_loop()

#include "gamemanager.h"

int main(int argc, char const *argv[])
{
    
    gamemanager game;
    game.start_game();
    return 0;
}