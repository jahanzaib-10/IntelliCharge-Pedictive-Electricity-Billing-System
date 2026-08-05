#ifndef PREDICTION_H
#define PREDICTION_H

#include <string>
#include <vector>
#include <algorithm>
#include "User.h"
using namespace std;

struct PredictionResult {
    int predictedUnits;
    string trend;
    int confidence;
    string model;
    vector<string> factors;
};

class Prediction {
public:
    PredictionResult predict(const User& user) const {
        PredictionResult r;
        int cur = user.getCurrentUnits();
        int prev = user.getPreviousUnits(); 

        r.predictedUnits = max(0, cur + (cur - prev) / 2);
        r.model = "Linear Growth Model";

        if (cur > prev) {
            r.trend = "increasing";
            r.factors.push_back("Usage trending upward");
        } else if (cur < prev) {
            r.trend = "decreasing";
            r.factors.push_back("Usage trending downward");
        } else {
            r.trend = "stable";
            r.factors.push_back("Stable usage pattern");
        }

        r.confidence = 85;
        r.factors.push_back("Seasonal variations may affect usage");

        return r;
    }
};

#endif
