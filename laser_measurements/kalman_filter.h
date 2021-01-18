//
// Created by sajith on 1/18/21.
//

#ifndef KALMAN_FILTER_KALMAN_FILTER_H
#define KALMAN_FILTER_KALMAN_FILTER_H

#include "../Eigen/Dense"

using Eigen::MatrixXd;
using Eigen::VectorXd;

class KalmanFilter
{
public:
    KalmanFilter();

    virtual ~KalmanFilter();

    void Predict();

    void Update(const VectorXd &z);

    VectorXd x_;

    MatrixXd P_;

    MatrixXd F_;

    MatrixXd Q_;

    MatrixXd H_;

    MatrixXd R_;

};


#endif //KALMAN_FILTER_KALMAN_FILTER_H
