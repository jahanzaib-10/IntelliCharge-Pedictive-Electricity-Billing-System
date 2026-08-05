#include <iostream>
#include <string>
#include "User.h"
#include "FileHandler.h"
#include "BillCalculator.h"
#include "Prediction.h"
#include "Charge.h"

using namespace std;

int main() {
    cout << "[C++] IntelliCharge Calculator Engine Starting...\n";

    try {
        FileHandler fileHandler("data/input.txt", "data/output.txt");

        cout << "[C++] Reading input file...\n";
        User user = fileHandler.readInputFile();
        cout << "[C++] User loaded: " << user.getName() << endl;

        // select charge type based on user input
        Charge* chargeStrategy = nullptr;
        string type = user.getCustomerType();

        if (type == "Domestic" || type == "domestic") {
            chargeStrategy = new DomesticCharge();
        }
        else if (type == "Commercial" || type == "commercial") {
            chargeStrategy = new CommercialCharge();
        }
        else if (type == "Industrial" || type == "industrial") {
            chargeStrategy = new IndustrialCharge();
        }
        else {
            throw runtime_error("Invalid customer type in input file");
        }

        cout << "[C++] Calculating bill...\n";
        BillCalculator calculator(chargeStrategy);
        BillBreakdown bill = calculator.calculateBill(user);

        cout << "[C++] Running prediction...\n";
        Prediction predictor;
        PredictionResult prediction = predictor.predict(user);

        cout << "[C++] Writing output file...\n";
        fileHandler.writeOutputFile(user, bill, prediction);

        delete chargeStrategy;

        cout << "[C++] Processing complete!\n";
        return 0;
    }
    catch (const exception& e) {
        cerr << "[C++] Error: " << e.what() << endl;
        return 1;
    }
}
