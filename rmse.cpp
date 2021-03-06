#include <iostream>
#include <vector>
#include "Eigen/Dense"

using namespace std;
using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::cout;
using std::vector;


VectorXd CalculateRMSE(const vector<VectorXd> &estimations, const vector<VectorXd> &groud_truth);

int main()
{

    vector<VectorXd> estimations;
    vector<VectorXd> ground_truth;

    VectorXd e(4);
    e << 1, 1, 0.2, 0.1;
    estimations.push_back(e);
    e << 2, 2, 0.3, 0.2;
    estimations.push_back(e);
    e << 3, 3, 0.4, 0.3;
    estimations.push_back(e);

    VectorXd g(4);
    g << 1.1, 1.1, 0.3, 0.2;
    ground_truth.push_back(g);
    g << 2.1, 2.1, 0.4, 0.3;
    ground_truth.push_back(g);
    g << 3.1, 3.1, 0.5, 0.4;
    ground_truth.push_back(g);

    // call the CalculateRMSE and print out the result
    cout << CalculateRMSE(estimations, ground_truth) << "\n";

    return 0;
}


VectorXd CalculateRMSE(const vector<VectorXd> &estimations, const vector<VectorXd> &ground_truth)
{
    VectorXd rmse(4);
    rmse << 0, 0, 0, 0;

    if (estimations.size() != ground_truth.size() or estimations.empty())
    {
        cout << "Invalid estimation or ground thruth data\n";
        return rmse;
    }

    // accumulate squared residuals
    for (int i = 0; i < estimations.size(); ++i)
    {
        VectorXd residual = estimations[i] - ground_truth[i];
        residual = residual.array() * residual.array();
        rmse += residual;
    }

    rmse = rmse / estimations.size();
    rmse = rmse.array().sqrt();

    return rmse;
}


