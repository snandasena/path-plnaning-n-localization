#include <iostream>
#include "Eigen/Dense"

using namespace std;
using Eigen::VectorXd;
using Eigen::MatrixXd;

int main()
{

    VectorXd x(2);
    x << 10, 20;
    cout << x << "\n";

    MatrixXd mtrx(2, 2);
    mtrx << 1, 2,
            3, 4;

    cout << mtrx << "\n";
    return 0;

}
