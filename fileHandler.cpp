#include <iostream>
#include "fileHandler.h"
#include <fstream>

void loadExpenditures(Expenditure expenditures[], int& numExpenditures) {
    std::ifstream file("data/expenditures.txt");
    if (file.is_open()) {
        while (file >> expenditures[numExpenditures].category >> expenditures[numExpenditures].subCategory >> expenditures[numExpenditures].amount
                    >> expenditures[numExpenditures].date) {
            file.ignore();  // Ignore newline after date
            std::getline(file, expenditures[numExpenditures].description);  // Read description
            ++numExpenditures;
        }
        file.close();
    } else {
        std::cout << "Expenditure file not found, starting fresh.\n";
    }
}

void saveExpenditures(Expenditure expenditures[], int numExpenditures) {
    std::ofstream file("data/expenditures.txt");
    if (file.is_open()) {
        for (int i = 0; i < numExpenditures; ++i) {
            file << expenditures[i].category << " "
                 << expenditures[i].subCategory << " "
                 << expenditures[i].amount << " "
                 << expenditures[i].date << " "
                 << expenditures[i].description << "\n";
        }
        file.close();
    } else {
        std::cerr << "Failed to save expenditures.\n";
    }
}
