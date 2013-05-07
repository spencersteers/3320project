// Author: Spencer Steers
// Date:   05.07.2013
// File:   rng.h
// Definition of singleton class rng that centralizes random
// number generator calculations and probabilities

#ifndef __3320project__rng__
#define __3320project__rng__



#include <ctime>
#include <cstdlib>
#include <iostream>

class rng
{
public:

    // Pre: None
    // Post: returns the rng instance to use with other functions
    //       (ensures that the rng is only seeded once)
    static rng& get_instance();

    // Pre: An integer representing chance of true out of 100
    // Post: returns true/false based on probability
    bool probability(int probability);

    // Pre: Integer representing min/max value
    // Post: An integer in the range [min, max)
    int range(int max, int min = 0);

private:
    rng() {};
    ~rng();
    static rng* instance;
};


#endif
