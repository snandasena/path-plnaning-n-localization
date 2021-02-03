#include <iostream>
#include <random>

using namespace std;

void printSamples(double gps_x, double gps_y, double theta);

int main()
{
    double gps_x = 4983.0;
    double gps_y = 5029.0;
    double theta = 1.20;


    printSamples(gps_x, gps_y, theta);
    return 0;
}

void printSamples(double gps_x, double gps_y, double theta)
{
    std::default_random_engine gen;
    // set standard deviations for x,y, and theta
    double std_x, std_y, std_theta;
    std_x = 2;
    std_y = 2;
    std_theta = 0.05;

    // create normal(Guassinan) distribution for x
    std::normal_distribution<double> dist_x(gps_x, std_x);

    // create nomal distributions for y and theta
    std::normal_distribution<double> dist_y(gps_y, std_y);
    std::normal_distribution<double> dist_theta(theta, std_theta);

    double sample_x, sample_y, sample_theta;
    for (int i = 0; i < 3; ++i)
    {
        sample_x = dist_x(gen);
        sample_y = dist_y(gen);
        sample_theta = dist_theta(gen);

        // print
        cout << "Sample " << i << " " << sample_x << " " << sample_y << " " << sample_theta << "\n";
    }

}
