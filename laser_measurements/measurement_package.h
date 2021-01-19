//
// Created by sajith on 1/18/21.
//

#ifndef KALMAN_FILTER_MEASUREMENT_PACKAGE_H
#define KALMAN_FILTER_MEASUREMENT_PACKAGE_H

#include "../Eigen/Dense"

using Eigen::VectorXd;

class MeasurementPackage
{
public:
    enum SensorType
    {
        LASER, RADAR
    } sensor_type_;

    VectorXd raw_measurements_;
    int64_t timestamp_;
};

#endif //KALMAN_FILTER_MEASUREMENT_PACKAGE_H
