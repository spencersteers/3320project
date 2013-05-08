// Author: Spencer Steers
// Date:   05.07.2013
// File:   weapon.h
// Definition of class weapon; contains damage, name, and hit chance


#ifndef __3320project__weapon__
#define __3320project__weapon__

#include <string>

class weapon
{
public:
    weapon(std::string n, int d, int hc);


    /* Getters */
    std::string get_name();
    int get_damage();
    int get_hit_chance();


private:
    std::string name;
    int damage;
    int hit_chance;
};



#endif
