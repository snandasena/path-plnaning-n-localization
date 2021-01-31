//
// Created by sajith on 1/31/21.
//

#include <iostream>
#include "helpers.h"
#include <vector>

using namespace std;

vector<float> initialize_priors(int map_size, vector<float> landmark_positions, float position_std);

float motion_model(float pseudo_position, float movement, vector<float> priors, int map_size, float control_stdev);

int main()
{

    // set standard deviation of control
    float control_stdev = 1.0f;

    // set standard deviation of positions
    float position_stdev = 1.0f;
    // meters vehicle moves per time step;
    float movement_per_timestep = 1.0f;

    // number of x positions of map
    int map_size = 25;

    // initialize landmarks
    vector<float> landmarks_positions{5, 10, 20};

    // initialize priors
    vector<float> priors = initialize_priors(map_size, landmarks_positions, position_stdev);

    // step through each pseudo position x (i)
    for (float i = 0; i < map_size; ++i)
    {
        float pseudo_position = i;
        // get the motion model probability for each x position
        float motion_prob = motion_model(pseudo_position, movement_per_timestep, priors, map_size, control_stdev);

        cout << pseudo_position << "\t" << motion_prob << "\n";
    }
    return 0;
}

float motion_model(float pseudo_position, float movement, vector<float> priors, int map_size, float control_stdev)
{
    float position_prob = 0.0f;
    for (float j = 0; j < map_size; ++j)
    {
        float next_pseudo_position = j;

        // distance from i to j
        float distance_ij = pseudo_position - next_pseudo_position;

        // transition probabilities:
        float transition_prob = Helpers::normpdf(distance_ij, movement, control_stdev);

        // estimate probability for the motion model, this is our prior
        position_prob += transition_prob * priors[j];

    }
    return position_prob;

}


vector<float> initialize_priors(int map_size, vector<float> landmark_positions, float position_std)
{

    // set all priors to 0.0
    vector<float> priors(map_size, 0.0);

    float norm_term = landmark_positions.size() * (position_std * 2 + 1);
    for (int i = 0; i < landmark_positions.size(); ++i)
    {
        for (float j = 1; j <= position_std; ++j)
        {
            priors.at(int(j + landmark_positions[i] + map_size) % map_size) += 1.0 / norm_term;
            priors.at(int(-j + landmark_positions[i] + map_size) % map_size) += 1.0 / norm_term;
        }
        priors.at(landmark_positions[i]) += 1.0 / norm_term;
    }

    return priors;

}