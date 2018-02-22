#ifndef AQUACLASSES_H
#define AQUACLASSES_H

#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <iomanip>

// Constants
const short int AMT_FISH = 200;
const short int AMT_KILLER_WHALES = 2;
const short int AMT_PENGUINS = 50;
const short int MAX_SIM_INTERATIONS = 10000;
const short int MAX_SEA = 625;
const short int MAX_SEA_GRID = 25;

// Functions
template <typename TYPE> int calculate_distance (int obj1_x, int obj1_y,
                                                 TYPE obj2);
template <typename TYPE> int calculate_direction (int obj1_x, int obj1_y,
                                                  TYPE obj2);

#endif