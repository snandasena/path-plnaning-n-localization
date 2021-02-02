//
// Created by sajith on 2/2/21.
//

#ifndef KALMAN_FILTER_HELPERS_H
#define KALMAN_FILTER_HELPERS_H

#include <cmath>
#include <vector>

class Helpers
{

public:
    constexpr static float ONE_OVER_SQRT_2PI = 1 / sqrt(2 * M_PI);

    static float normpdf(float x, float mu, float stdev)
    {
        return (ONE_OVER_SQRT_2PI / stdev) * exp(-0.5 * pow((x - mu) / stdev, 2));
    }

    static std::vector<float> normalize_vector(std::vector<float> inputvector)
    {
        float sum = 0.0f;

        std::vector<float> outputvector(inputvector.size());

        for (auto inputValue: inputvector)
        {
            sum += inputValue;
        }

        for (int i = 0; i < inputvector.size(); ++i)
        {
            outputvector[i] = inputvector[i] / sum;
        }

        return outputvector;

    }
};

#endif //KALMAN_FILTER_HELPERS_H
