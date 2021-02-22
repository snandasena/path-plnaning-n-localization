//
// Created by sajith on 2/21/21.
//

#include "hybrid_breadth_first.h"
#include <cmath>
#include <iostream>
#include <vector>

HBF::HBF() {}

HBF::~HBF() {}


bool HBF::compare_maze_s(const HBF::maze_s &lhs, const HBF::maze_s &rhs)
{
    return lhs.f < rhs.f;
}


double HBF::heuristic(double x, double y, vector<int> &goal)
{
    return fabs(y - goal[0]) + fabs(x - goal[1]);
}

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

vector<HBF::maze_s> HBF::expand(HBF::maze_s &state)
{
    int g = state.g;
    double x = state.x;
    double y = state.y;
    double theta = state.theta;

    int g2 = g + 1;
    vector<HBF::maze_s> next_states;

    for (double delta_i = -35.0; delta_i < 40.0; delta_i += 5)
    {
        double delta = M_PI / 180.0 * delta_i;
        double omega = SPEED / LENGTH * tan(delta);
        double theta2 = theta + omega;

        if (theta2 < 0)
        {
            theta2 += 2 * M_PI;
        }

        double x2 = x + SPEED * cos(theta);
        double y2 = y + SPEED * sin(theta);

        HBF::maze_s state2;
        state2.g = g2;
        state2.x = x2;
        state2.y = y2;
        state2.theta = theta2;

        next_states.emplace_back(state2);
    }

    return next_states;
}


vector<HBF::maze_s> HBF::reconstruct_path(vector<vector<vector<HBF::maze_s>>> &came_from, vector<double> &start,
                                          HBF::maze_s &final)
{

    vector<maze_s> path = {final};
    int stack = theta_to_stack_number(final.theta);
    maze_s current = came_from[stack][idx(final.x)][idx(final.y)];

    stack = theta_to_stack_number(current.theta);

    double x = current.x;
    double y = current.y;

    while (x != start[0] || y != start[1])
    {
        path.emplace_back(current);
        current = came_from[stack][idx(x)][idx(y)];
        x = current.x;
        y = current.y;

        stack = theta_to_stack_number(current.theta);
    }

    return path;
}

HBF::maze_path HBF::search(vector<vector<int>> &grid, vector<double> &start, vector<int> &goal)
{
    vector<vector<vector<int >>> closed(NUM_THETA_CELLS,
                                        vector<vector<int>>(grid[0].size(), vector<int>(grid.size())));


    vector<vector<vector<maze_s>>> came_from(NUM_THETA_CELLS,
                                             vector<vector<maze_s>>(grid[0].size(), vector<maze_s>(grid.size())));

    double theta = start[2];
    int stack = theta_to_stack_number(theta);
    int g = 0;
    maze_s state;

    state.g = g;
    state.x = start[0];
    state.y = start[1];
    state.f =

}