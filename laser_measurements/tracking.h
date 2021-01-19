//
// Created by sajith on 1/18/21.
//

#ifndef KALMAN_FILTER_TRACKING_H
#define KALMAN_FILTER_TRACKING_H

#include <vector>
#include <string>
#include <fstream>
#include "kalman_filter.h"
#include "measurement_package.h"

using Eigen::MatrixXd;
using Eigen::VectorXd;


class Tracking
{
public:
    Tracking();

    virtual ~Tracking();

    void ProcessMeasurement(const MeasurementPackage &measurement_pack);

    KalmanFilter kf_;

private:
    bool is_initialized_;
    int64_t previous_timestamp_;

    // increase the noise component
    float noise_ax;
    float noise_ay;
};

#endif //KALMAN_FILTER_TRACKING_H
