#include "expenditure.h"

float calculateTotalExpenditure(Expenditure expenditures[], int numExpenditures) {
    float total = 0;
    for (int i = 0; i < numExpenditures; ++i) {
        total += expenditures[i].amount;
    }
    return total;
}

double calculateCategoryTotal(Expenditure expenditures[], int numExpenditures, const std::string& category) {
    double categoryTotal = 0;
    for (int i = 0; i < numExpenditures; ++i) {
        if (expenditures[i].category == category) {
            categoryTotal += expenditures[i].amount;
        }
    }
    return categoryTotal;
}

double calculateSubCategoryTotal(Expenditure expenditures[], int numExpenditures, const std::string& category, const std::string& subCategory) {
    double subCategoryTotal = 0;
    for (int i = 0; i < numExpenditures; ++i) {
        if (expenditures[i].category == category && expenditures[i].subCategory == subCategory) {
            subCategoryTotal += expenditures[i].amount;
        }
    }
    return subCategoryTotal;
}
