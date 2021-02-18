//
// Created by sajith on 2/18/21.
//

#ifndef KALMAN_FILTER_CLASSIFIER_H
#define KALMAN_FILTER_CLASSIFIER_H

#include <string>
#include <vector>
#include "../Eigen/Dense"

using Eigen::ArrayXd;
using std::string;
using std::vector;

class GNB
{
public:

    // constructor
    GNB();

    // destructor
    virtual ~GNB();

    void train(const vector<vector<double>> &data, const vector<string> &labels);

    string predict(const vector<double> &sample);

    vector<string> possible_labels{"left", "keep", "right"};

    ArrayXd left_means;
    ArrayXd left_sds;
    double left_prior;

    ArrayXd keep_means;
    ArrayXd keep_sds;
    double keep_prior;

    ArrayXd right_means;
    ArrayXd right_sds;
    double right_prior;

};

#endif //KALMAN_FILTER_CLASSIFIER_H
