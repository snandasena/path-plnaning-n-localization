#include <algorithm>
#include <iostream>
#include <vector>
#include "helpers.h"

using namespace std;

// set standard deviation of control
float control_stdev = 1.0f;

float observation_stdev = 1.0f;

// meters vehicle moves per time step
float movement_per_timestep = 1.0f;

// number of x position on map
int map_size = 25;

float distance_max = map_size;

// define landmarks
vector<float> landmark_positions{5, 10, 12, 20};

// define observations
vector<float> observations{5.5, 13, 15};

// define pseudo range estimator function
vector<float> pseudo_range_estimator(vector<float> landmark_positions, float pseudo_position);

float observation_model(vector<float> landmark_positions, vector<float> observations, vector<float> pseudo_ranges,
                        float distance_max, float observation_stdev);

int main()
{

    for (int i = 0; i < map_size; ++i)
    {
        float pseudo_position = float(i);

        // get pseudo ranges
        vector<float> pseudo_ranges = pseudo_range_estimator(landmark_positions, pseudo_position);

        // get observation probability
        float observation_prob = observation_model(landmark_positions, observations, pseudo_ranges, distance_max,
                                                   observation_stdev);

        cout << observation_prob << " \n";
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


float observation_model(vector<float> landmark_positions, vector<float> observations, vector<float> pseudo_ranges,
                        float distance_max, float observation_stdev)
{
    float distance_prob = 1.0f;
    for (int i = 0; i < observations.size(); ++i)
    {
        // define min distance
        float pseudo_range_min;
        if (!pseudo_ranges.empty())
        {
            // set min distance
            pseudo_range_min = pseudo_ranges[0];

            // remove this entry vector from pseudo_range_vector
            pseudo_ranges.erase(pseudo_ranges.begin());
        }
        else
        {
            // no or negative distances: set min distance to a large number
            pseudo_range_min = std::numeric_limits<const float>::infinity();


        }

        // estimate the probability for observation model, this is our likehood
        distance_prob *= Helpers::normpdf(observations[i], pseudo_range_min, observation_stdev);

    }
    return distance_prob;
}