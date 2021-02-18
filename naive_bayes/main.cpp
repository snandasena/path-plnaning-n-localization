#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "classifier.h"

using namespace std;


vector<vector<double>> Load_State(const string &fileName);

vector<string> Load_Label(const string &fileName);


int main()
{

    const string train_state = "../data/train_states.txt";
    const string test_state = "../data/test_states.txt";
    const string train_label = "../data/train_labels.txt";
    const string test_label = "../data/test_labels.txt";

    vector<vector<double >> X_train = Load_State(train_state);
    vector<vector<double >> X_test = Load_State(test_state);

    vector<string> Y_train = Load_Label(train_label);
    vector<string> Y_test = Load_Label(test_label);


    cout << "X_train number of elements " << X_train.size() << endl;
    cout << "X_train element size " << X_train[0].size() << endl;
    cout << "Y_train number of elements " << Y_train.size() << endl;

    GNB gnb;
    gnb.train(X_train, Y_train);

    cout << "\n";
    cout << "X_test number of elements " << X_test.size() << endl;
    cout << "X_test element size " << X_test[0].size() << endl;
    cout << "Y_test number of elements " << Y_test.size() << endl;

    int score = 0;

    for (int i = 0; i < X_test.size(); ++i)
    {
        vector<double> coords = X_test[i];
        string predicted = gnb.predict(coords);

        if (predicted == Y_test[i])
        {
            score++;
        }
    }

    float fraction_correct = float(score) / Y_test.size();
    cout << "You got " << (100 * fraction_correct) << " correct" << endl;

    return 0;

}


vector<vector<double>> Load_State(const string &fileName)
{
    ifstream in_state(fileName.c_str(), ifstream::in);
    vector<vector<double>> state_out;

    string line;

    while (getline(in_state, line))
    {
        std::istringstream iss(line);
        vector<double> x_coord;

        string token;
        while (getline(iss, token, ','))
        {
            x_coord.emplace_back(stod(token));
        }

        state_out.emplace_back(x_coord);
    }

    return state_out;
}


vector<string> Load_Label(const string &fileName)
{
    ifstream in_label(fileName.c_str(), ifstream::in);
    vector<string> label_out;
    string line;

    while (getline(in_label, line))
    {
        std::istringstream iss(line);
        string label;
        iss >> label;

        label_out.emplace_back(label);
    }

    return label_out;
}