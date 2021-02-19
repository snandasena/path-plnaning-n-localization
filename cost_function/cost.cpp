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
    double speed_inteded = lane_speeds[intended_lane] * 1.0;
    double speed_final = lane_speeds[final_lane] * 1.0;

    return (2.0 * target_speed - speed_inteded - speed_final) / target_speed;

}