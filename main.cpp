#include <iostream>
#include <vector>
#include "Eigen/Dense"

using namespace std;
using Eigen::VectorXd;
using Eigen::MatrixXd;

VectorXd x(2); // Object data
MatrixXd P(2, 2); // Object covariance data
VectorXd u(2); // external mortion
MatrixXd F(2, 2); // state transition matrix
MatrixXd H(1, 2); // Measurement matrix;
MatrixXd R(1, 1); // Measurement covariance matrix
MatrixXd I; // Identity matrix
MatrixXd Q(2, 2); // Process covariance matrix

vector<VectorXd> measurements;

void filter(VectorXd &x, MatrixXd &p);


int main()
{

    // design the KF with 1-D mortion
    x << 0, 0;
    P << 1000, 0, 0, 1000;
    u << 0, 0;
    F << 1, 1, 0, 1;
    H << 1, 0;
    I = MatrixXd::Identity(2, 2);
    Q << 0, 0, 0, 0;

    VectorXd single_means(1);
    single_means << 1;
    measurements.emplace_back(single_means);
    single_means << 2;
    measurements.emplace_back(single_means);
    single_means << 3;
    measurements.emplace_back(single_means);

    filter(x, P);
    return 0;
}

void filter(VectorXd &x, MatrixXd &P)
{
    for (int n = 0; n < measurements.size(); ++n)
    {
        VectorXd z = measurements[n];

        // KF measurement update step
        VectorXd y = z - H * x;
        MatrixXd Ht = H.transpose();
        MatrixXd S = H * P * Ht + R;
        MatrixXd Si = S.inverse();
        MatrixXd K = P * Ht * Si;

        // New state
        x = F * x + u;
        MatrixXd Ft = F.transpose();
        P = F * P * Ft + Q;

        cout << "x = \n" << x << "\n";
        cout << "P = \n" << P << "\n";
    }
}
