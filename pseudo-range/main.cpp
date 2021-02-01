#include <algorithm>
#include <iostream>
#include <vector>
#include "helpers.h"

using namespace std;

// set standard deviation of control
float control_stdev = 1.0f;

// meters vehicle moves per time step
float movement_per_timestep = 1.0f;

// number of x position on map
int map_size = 25;


// define landmarks
vector<float> landmark_positions{5, 10, 12, 20};

// define pseudo range estimator function
vector<float> pseudo_range_estimator(vector<float> landmark_positions, float pseudo_position);

int main()
{

    for (int i = 0; i < map_size; ++i)
    {
        float pseudo_position = float(i);
        vector<float> pseudo_ranges = pseudo_range_estimator(landmark_positions, pseudo_position);

        if (!pseudo_ranges.empty())
        {
            for (auto pseudo_r : pseudo_ranges)
            {
                cout << "x: " << i << "\t" << pseudo_r << "\n";
            }

            cout << "------------------------\n";
        }
    }
    return 0;
}


vector<float> pseudo_range_estimator(vector<float> landmark_positions, float pseudo_position)
{
    // define pseudo observation vector
    vector<float> pseudo_ranges;
    for (int i = 0; i < landmark_positions.size(); ++i)
    {
        float range_l = landmark_positions[i] - pseudo_position;
        if (range_l > 0.0f) pseudo_ranges.emplace_back(range_l);
    }

    sort(pseudo_ranges.begin(), pseudo_ranges.end());
    return pseudo_ranges;
}