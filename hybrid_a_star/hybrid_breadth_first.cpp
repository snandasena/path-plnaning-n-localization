//
// Created by sajith on 2/21/21.
//

#include "hybrid_breadth_first.h"
#include <cmath>
#include <iostream>
#include <vector>

HBF::HBF() {}

HBF::~HBF() {}

int HBF::theta_to_stack_number(double theta)
{
    double new_theta = fmod(theta + 2 * M_PI, 2 * M_PI);
    int stack_number = (int) (round(new_theta * NUM_THETA_CELLS / (2 * M_PI))) % NUM_THETA_CELLS;
    return stack_number;
}


int HBF::idx(double float_num)
{
    return int(floor(float_num));
}

