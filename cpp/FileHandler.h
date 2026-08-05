#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <stdexcept>
#include "User.h"
#include "BillCalculator.h"
#include "Prediction.h"

using namespace std;

class FileHandler {
private:
    string inputPath;
    string outputPath;

    // current date and time
    string getTimestamp() const {
        time_t now = time(0);
        char buffer[80];
        tm* timeinfo = localtime(&now);
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
        return string(buffer);
    }

public:
    FileHandler(const string& input, const string& output)
        : inputPath(input), outputPath(output) {}

    // read user data from input file
    User readInputFile() const {
        ifstream file(inputPath);
        if (!file.is_open())
            throw runtime_error("Cannot open input file");

        string name, type, line;
        int currentUnits, previousUnits;

        getline(file, name);          
        getline(file, line);
        currentUnits = stoi(line);    

        getline(file, line);
        previousUnits = stoi(line);   

        getline(file, type);          

        file.close();

        return User(name, currentUnits, previousUnits, type);
    }

    
    void writeOutputFile(const User& user,
                         const BillBreakdown& bill,
                         const PredictionResult& prediction) const {

        ofstream file(outputPath);
        if (!file.is_open())
            throw runtime_error("Cannot open output file");

        file << fixed << setprecision(2);

        file << "=====================================\n";
        file << "     INTELLICHARGE BILLING REPORT\n";
        file << "=====================================\n\n";

        file << "Customer Name: " << user.getName() << endl;
        file << "Customer Type: " << user.getCustomerType() << endl;
        file << "Units Consumed: " << user.getCurrentUnits() << endl;
        file << "Generated On: " << getTimestamp() << "\n\n";

        file << "----------- BILL BREAKDOWN -----------\n";
        file << "Base Charge:       PKR " << bill.baseCharge << endl;
        file << "Fuel Adjustment:   PKR " << bill.fcaCharge << endl;
        file << "Fixed Charges:     PKR " << bill.fixedCharges << endl;
        file << "Tax:               PKR " << bill.tax << endl;
        file << "TOTAL BILL:        PKR " << bill.totalBill << endl;
        file << "-------------------------------------\n";
        file << "TOTAL BILL:        PKR " << bill.totalBill << endl;
        file << "-------------------------------------\n\n";

        file << "---------- USAGE PREDICTION ----------\n";
        file << "Predicted Units: " << prediction.predictedUnits << endl;
        file << "Trend: " << prediction.trend << endl;
        file << "Confidence: " << prediction.confidence << "%\n";
        file << "Model Used: " << prediction.model << "\n\n";

        file << "Factors:\n";
        for (const auto& f : prediction.factors) {
            file << "- " << f << endl;
        }

        file << "\n=====================================\n";
        file << "           END OF REPORT\n";
        file << "=====================================\n";

        file.close();
    }
};

#endif
