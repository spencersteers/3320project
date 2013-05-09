*** Compiling ***
g++ *.cpp


*** Code ***
s
Classes:
    gamemanager
    rng
    room
    actor
    weapon

gamemanager
    - uses a finite state machine in main_loop()
    - each state triggers jumps to new states
    - flows in descending order unless death or victory occurs

    - handles battle inside battle() function

rng
    - singleton object 
    - handles generating random nubers and ranges
    - prevents having srand called multiple times
    - used for battle and moving player through castle

room
    - has knowledge of what enemy is in the room
    - what rooms its connected too
    - gamemanager responsible for switching between rooms

actor
    - represents players and enemies
    - contains functions for battle statistics, death ect
    - factory method for generating player
    - factory method for generating random enemy

weapon
    - holds weapon stats
    - factory method for generating random player weapon
    - factory method for generating random enemy weapon