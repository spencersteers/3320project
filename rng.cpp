// Author: Spencer Steers
// Date:   05.07.2013
// File:   rng.cpp
// Implmentation of singleton class rng

#include "rng.h"

rng* rng::instance = 0;

rng& rng::get_instance()
{

    if (instance == NULL)
    {
        instance = new rng;
        srand(time(NULL));
    }

    return *instance;
}

bool rng::probability(int probability)
{
    int rval = rand() % 100;
    return probability > rval;
}

int rng::range(int max, int min)
{
    int rval = rand() % (max - min);
    return rval += min; 
}


rng::~rng()
{
    delete instance;
    instance = 0;
}