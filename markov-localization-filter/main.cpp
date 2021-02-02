#include <iostream>
#include <algorithm>
#include <vector>
#include "helpers.h"


using namespace std;


vector<float> initialize_priors(int map_size, vector<float> landmark_positions, float position_stdev);

float motion_model(float pseudo_position, float movement, vector<float> priors, int map_size, float control_stdev);

vector<float> pseudo_range_estimator(vector<float> landmark_positions, float pseudo_position);

float observation_model(vector<float> landmark_positions, vector<float> observations, vector<float> pseudo_ranges,
                        float distance_max, float observation_stdev);


int main()
{

    float controal_stdev = 1.0f;
    float position_stdev = 1.0f;
    float movement_per_timestep = 1.0f;
    float observation_stdev = 1.0f;
    int map_size = 25;
    float distance_max = map_size;
    vector<float> landmark_positions{3, 9, 14, 23};
    // define observations vector, each inner vector represents a set
    //   of observations for a time step
    vector<vector<float> > sensor_obs{{1, 7,  12, 21},
                                      {0, 6,  11, 20},
                                      {5, 10, 19},
                                      {4, 9,  18},
                                      {3, 8,  17},
                                      {2, 7,  16},
                                      {1, 6,  15},
                                      {0, 5,  14},
                                      {4, 13},
                                      {3, 12},
                                      {2, 11},
                                      {1, 10},
                                      {0, 9},
                                      {8},
                                      {7},
                                      {6},
                                      {5},
                                      {4},
                                      {3},
                                      {2},
                                      {1},
                                      {0},
                                      {},
                                      {},
                                      {}};


    // initialize priors
    vector<float> priors = initialize_priors(map_size, landmark_positions, position_stdev);

    cout << "---------------- PRIOR INIT----------------\n";
    for (auto prior: priors)
    {
        cout << prior << "\n";
    }

    // initialize posteriors
    vector<float> posteriors(map_size, 0.0);

    // specify time steps
    int time_steps = sensor_obs.size();
    vector<float> observations;

    for (int t = 0; t < time_steps; ++t)
    {
        cout << "---------------TIME STEP---------------" << endl;
        cout << "t = " << t << endl;
        cout << "-----Motion----------OBS----------------PRODUCT--" << endl;

        if (!sensor_obs[t].empty())
        {
            observations = sensor_obs[t];
        }
        else
        {
            observations = {float(distance_max)};
        }

        // step through each step position x (i)
        for (int i = 0; i < map_size; ++i)
        {
            float pseudo_position = float(i);

            // get the motion model probability for each x position
            float motion_probability = motion_model(pseudo_position, movement_per_timestep, priors, map_size,
                                                    controal_stdev);

            // get pseudo ranges
            vector<float> pseudo_ranges = pseudo_range_estimator(landmark_positions, pseudo_position);

            // get observation probability
            float observation_prob = observation_model(landmark_positions, observations, pseudo_ranges, distance_max,
                                                       observation_stdev);
            // calculate the ith postirior
            posteriors[i] = motion_probability * observation_prob;


            cout << motion_probability << "\t" << observation_prob << "\t" << "\t"
                 << motion_probability * observation_prob << endl;
        }

        // normalize
        posteriors = Helpers::normalize_vector(posteriors);

        cout << posteriors[t] << "\t" << priors[t] << endl;
        cout << "----------NORMALIZED---------------" << endl;

        priors = posteriors;
        for (int p = 0; p < posteriors.size(); ++p)
        {
            cout << posteriors[p] << endl;
        }

    }

    return 0;
}


float observation_model(vector<float> landmark_positions, vector<float> observations, vector<float> pseudo_ranges,
                        float distance_max, float observation_stdev)
{
    float distance_prob = 1.0f;
    for (int z = 0; z < observations.size(); ++z)
    {
        float pseudo_range_min;

        if (!pseudo_ranges.empty())
        {
            pseudo_range_min = pseudo_ranges[0];
            pseudo_ranges.erase(pseudo_ranges.begin());
        }
        else
        {
            pseudo_range_min = std::numeric_limits<const float>::infinity();
        }

        distance_prob *= Helpers::normpdf(observations[z], pseudo_range_min, observation_stdev);
    }

    return distance_prob;
}

vector<float> pseudo_range_estimator(vector<float> landmark_positions, float pseudo_position)
{
    vector<float> pseudo_ranges;

    for (int l = 0; l < landmark_positions.size(); ++l)
    {
        float range_l = landmark_positions[l] - pseudo_position;

        if (range_l > 0.0f)
        {
            pseudo_ranges.emplace_back(range_l);
        }
    }

    sort(pseudo_ranges.begin(), pseudo_ranges.end());
    return pseudo_ranges;
}

float motion_model(float pseudo_position, float movement, vector<float> priors, int map_size, float control_stdev)
{
    float position_prob = 0.0f;
    for (float j = 0; j < map_size; ++j)
    {
        float next_pseudo_position = j;

        float distance_ij = pseudo_position - next_pseudo_position;

        float transition_prob = Helpers::normpdf(distance_ij, movement, control_stdev);

        position_prob += transition_prob * priors[j];
    }

    return position_prob;
}

vector<float> initialize_priors(int map_size, vector<float> landmark_positions, float position_stdev)
{
    vector<float> priors(map_size, 0.0);

    float norm_term = landmark_positions.size() * (position_stdev * 2 + 1);
    for (int i = 0; i < landmark_positions.size(); ++i)
    {
        for (float j = 1; j <= position_stdev; ++j)
        {
            priors.at(int(j * landmark_positions[i] + map_size) % map_size) += 1.0 / norm_term;
            priors.at(int(-j * landmark_positions[i] + map_size) % map_size) += 1.0 / norm_term;
        }

        priors.at(landmark_positions[i]) += 1.0 / norm_term;
    }

    return priors;
}