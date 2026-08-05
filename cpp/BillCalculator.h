#ifndef BILLCALCULATOR_H
#define BILLCALCULATOR_H

#include <cmath>
#include <string>
#include "User.h"
#include "Charge.h"
using namespace std;

struct BillBreakdown {
    double baseCharge;
    double fcaCharge;
    double fixedCharges;
    double tax;
    double totalBill;
    string chargeType;

    BillBreakdown()
        : baseCharge(0), fcaCharge(0),
          fixedCharges(0), tax(0),
          totalBill(0), chargeType("") {}
};

class BillCalculator {
private:
    Charge* strategy;

public:
    BillCalculator(Charge* s) : strategy(s) {}

    BillBreakdown calculateBill(const User& user) const {
        BillBreakdown bill;
        int units = user.getCurrentUnits();

        bill.baseCharge = strategy->calculateCharge(units);
        bill.fcaCharge = units * 3.0;     
        bill.fixedCharges = 85.0;        

        double subtotal = bill.baseCharge + bill.fcaCharge + bill.fixedCharges;
        bill.tax = subtotal * 0.17;       
        bill.totalBill = subtotal + bill.tax;

        bill.chargeType = strategy->getName();
        return bill;
    }
};

#endif
