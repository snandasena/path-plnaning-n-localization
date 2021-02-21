//
// Created by sajith on 2/21/21.
//

#ifndef KALMAN_FILTER_HYBRID_BREADTH_FIRST_H
#define KALMAN_FILTER_HYBRID_BREADTH_FIRST_H

#include <vector>

using std::vector;

class HBF
{
    HBF();

    virtual ~HBF();

    // HBF structs
    struct maze_s
    {
        int g; // iterations
        double x;
        double y;
        double theta;
    };

    struct maze_path
    {
        vector<vector<vector<int>>> closed;
        vector<vector<vector<maze_s>>> came_from;
        maze_s final;
    };

    // HBF functions
    int theta_to_stack_number(double theta);

    int idx(double float_num);

    vector<maze_s> expand(maze_s &state);


    vector<maze_s> reconstruct_path(vector<vector<vector<maze_s>>> &came_from, vector<double> &start, maze_s &final);

    maze_path search(vector<vector<int>> &grid, vector<double> &start, vector<int> &goal);

private:

    const int NUM_THETA_CELLS = 90;
    const double SPEED = 1.45;
    const double LENGTH = 0.5;

};

#endif //KALMAN_FILTER_HYBRID_BREADTH_FIRST_H
