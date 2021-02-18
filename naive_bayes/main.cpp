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

};