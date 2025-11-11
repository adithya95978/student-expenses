#include "report.h"
#include <iostream>

void generateReport(Expenditure expenditures[], int numExpenditures, double globalBudget, CategoryBudget categoryBudgets[], int numCategoryBudgets) {
    double total = calculateTotalExpenditure(expenditures, numExpenditures);
    std::cout << "\nTotal Expenditure: " << total << std::endl;

    // Display global budget warning if exceeded
    if (total > globalBudget) {
        std::cout << "Warning: Total expenditure exceeds global budget!\n";
    }

    // Check category/subcategory budget limits
    for (int i = 0; i < numCategoryBudgets; ++i) {
        double categoryTotal = calculateCategoryTotal(expenditures, numExpenditures, categoryBudgets[i].category);
        double subCategoryTotal = calculateSubCategoryTotal(expenditures, numExpenditures, categoryBudgets[i].category, categoryBudgets[i].subCategory);
        double categoryLimit = categoryBudgets[i].monthlyLimit;

        std::cout << "Category: " << categoryBudgets[i].category
                  << ", Sub-category: " << categoryBudgets[i].subCategory
                  << ", Monthly Limit: " << categoryLimit
                  << ", Total Spent: " << subCategoryTotal << std::endl;

        // Warn if spending exceeds budget
        if (subCategoryTotal > categoryLimit) {
            std::cout << "Warning: You have exceeded your budget for this sub-category!\n";
        }
    }
}
