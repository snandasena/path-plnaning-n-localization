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

    // state vector
    VectorXd x_;

    // state covariance matrix
    MatrixXd P_;

    // state transition matrix
    MatrixXd F_;

    //process covariance matrix
    MatrixXd Q_;

    // measurement matrix
    MatrixXd H_;

    // measurement covariance matrix
    MatrixXd R_;

};


#endif //KALMAN_FILTER_KALMAN_FILTER_H
