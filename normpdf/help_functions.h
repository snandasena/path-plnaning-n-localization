#ifndef HELP_FUNCS_H
#define HELP_FUNCS_H

#include <cmath>

class Helpers
{
public:
    constexpr static float STATIC_ONE_OVER_SQRT_2PI = 1 / sqrt(2 * M_PI);

    static float normpdf(float x, float mu, float std)
    {
        return (STATIC_ONE_OVER_SQRT_2PI / std) * exp(-0.5 * pow((x - mu) / std, 2));
    }


};

#endif HELP_FUNCS_H