#ifndef USER_H
#define USER_H

#include <string>
#include <stdexcept>
using namespace std;

class User {
private:
    string name;
    int currentUnits;
    int previousUnits;
    string customerType;

    void validate() const {
        if (name.empty())
            throw invalid_argument("Name cannot be empty");
        if (currentUnits < 0 || previousUnits < 0)
            throw invalid_argument("Units cannot be negative");
        if (customerType.empty())
            throw invalid_argument("Customer type required");
    }

public:
    User() : name(""), currentUnits(0), previousUnits(0), customerType("") {}

    User(const string& n, int current, int previous, const string& type)
        : name(n), currentUnits(current), previousUnits(previous), customerType(type) {
        validate();
    }

    string getName() const { return name; }
    int getCurrentUnits() const { return currentUnits; }
    int getPreviousUnits() const { return previousUnits; }
    string getCustomerType() const { return customerType; }

    double getUsageChange() const {
        if (previousUnits == 0) return 0.0;
        return ((double)(currentUnits - previousUnits) / previousUnits) * 100.0;
    }
};

#endif
