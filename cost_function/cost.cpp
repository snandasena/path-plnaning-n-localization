//
// Created by sajith on 2/19/21.
//

#include "cost.h"
#include <cmath>

double goal_distance_cost(int goal_lane, int intended_lane, int final_lane,
                          double distance_to_goal)
{
    double delta_d = 2.0 * goal_lane - intended_lane - final_lane;
    return 1 - exp(-(std::abs(delta_d / distance_to_goal)));
}


double inefficiency_cost(int target_speed, int intended_lane, int final_lane,
                         const std::vector<int> &lane_speeds)
{

}