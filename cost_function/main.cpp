//
// Created by sajith on 2/19/21.
//

#include <iostream>
#include "cost.h"

using namespace std;

int main()
{
    int goal_lane = 0;

    // Test cases used for grading - do not change.
    double cost;
    cout << "Costs for (intended_lane, final_lane, goal_distance):" << endl;
    cout << "---------------------------------------------------------" << endl;
    cost = goal_distance_cost(goal_lane, 2, 2, 1.0);
    cout << "The cost is " << cost << " for " << "(2, 2, 1.0)" << endl;
    cost = goal_distance_cost(goal_lane, 2, 2, 10.0);
    cout << "The cost is " << cost << " for " << "(2, 2, 10.0)" << endl;
    cost = goal_distance_cost(goal_lane, 2, 2, 100.0);
    cout << "The cost is " << cost << " for " << "(2, 2, 100.0)" << endl;
    cost = goal_distance_cost(goal_lane, 1, 2, 100.0);
    cout << "The cost is " << cost << " for " << "(1, 2, 100.0)" << endl;
    cost = goal_distance_cost(goal_lane, 1, 1, 100.0);
    cout << "The cost is " << cost << " for " << "(1, 1, 100.0)" << endl;
    cost = goal_distance_cost(goal_lane, 0, 1, 100.0);
    cout << "The cost is " << cost << " for " << "(0, 1, 100.0)" << endl;
    cost = goal_distance_cost(goal_lane, 0, 0, 100.0);
    cout << "The cost is " << cost << " for " << "(0, 0, 100.0)" << endl;

// Target speed of our vehicle
    int target_speed = 10;

    // Lane speeds for each lane
    std::vector<int> lane_speeds = {6, 7, 8, 9};

    // Test cases used for grading - do not change.
    double cost;
    cout << "Costs for (intended_lane, final_lane):" << endl;
    cout << "---------------------------------------------------------" << endl;
    cost = inefficiency_cost(target_speed, 3, 3, lane_speeds);
    cout << "The cost is " << cost << " for " << "(3, 3)" << endl;
    cost = inefficiency_cost(target_speed, 2, 3, lane_speeds);
    cout << "The cost is " << cost << " for " << "(2, 3)" << endl;
    cost = inefficiency_cost(target_speed, 2, 2, lane_speeds);
    cout << "The cost is " << cost << " for " << "(2, 2)" << endl;
    cost = inefficiency_cost(target_speed, 1, 2, lane_speeds);
    cout << "The cost is " << cost << " for " << "(1, 2)" << endl;
    cost = inefficiency_cost(target_speed, 1, 1, lane_speeds);
    cout << "The cost is " << cost << " for " << "(1, 1)" << endl;
    cost = inefficiency_cost(target_speed, 0, 1, lane_speeds);
    cout << "The cost is " << cost << " for " << "(0, 1)" << endl;
    cost = inefficiency_cost(target_speed, 0, 0, lane_speeds);
    cout << "The cost is " << cost << " for " << "(0, 0)" << endl;

    return 0;
}