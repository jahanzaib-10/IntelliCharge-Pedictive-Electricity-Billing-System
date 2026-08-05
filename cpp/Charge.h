#ifndef CHARGE_H
#define CHARGE_H

#include <string>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Charge {
protected:
    string name;
    double rate;

public:
    Charge(const string& n, double r) : name(n), rate(r) {}
    virtual ~Charge() {}
    virtual double calculateCharge(int units) const = 0;
    string getName() const { return name; }
};

class DomesticCharge : public Charge {
    struct Slab { int limit; double rate; };
    vector<Slab> slabs;

public:
    DomesticCharge() : Charge("Domestic", 0) {
        slabs.push_back({50, 15});
        slabs.push_back({100, 25});
        slabs.push_back({200, 35});
        slabs.push_back({300, 40});
        slabs.push_back({700, 48});
        slabs.push_back({INT_MAX, 60});
    }

    double calculateCharge(int units) const override {
        double total = 0;
        int remaining = units, prev = 0;

        for (auto s : slabs) {
            int u = min(remaining, s.limit - prev);
            if (u <= 0) break;
            total += u * s.rate;
            remaining -= u;
            prev = s.limit;
        }
        return total;
    }
};

class CommercialCharge : public Charge {
public:
    CommercialCharge() : Charge("Commercial", 50) {}
    
    double calculateCharge(int units) const override {
        return units * rate + 3000;
    }
};
    
class IndustrialCharge : public Charge {
public:
    IndustrialCharge() : Charge("Industrial", 42) {}
    
    double calculateCharge(int units) const override {
       return units * rate;
    }
};

#endif
