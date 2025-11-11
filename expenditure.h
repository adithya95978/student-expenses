#ifndef EXPENDITURE_H
#define EXPENDITURE_H

#include <string>

struct Expenditure {
    std::string category;
    std::string subCategory; // Added sub-category
    double amount;
    std::string date;
    std::string description; // Added description
};

float calculateTotalExpenditure(Expenditure expenditures[], int numExpenditures);
double calculateCategoryTotal(Expenditure expenditures[], int numExpenditures, const std::string& category);
double calculateSubCategoryTotal(Expenditure expenditures[], int numExpenditures, const std::string& category, const std::string& subCategory);

struct CategoryBudget {
    std::string category;
    std::string subCategory;
    double monthlyLimit;
};

#endif // EXPENDITURE_H
