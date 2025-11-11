#include "budget.h"
#include <fstream>
#include <iostream>  // Add this include to resolve std::cout and std::cerr

double loadBudget() {
    double budget;
    std::ifstream file("data/budget.txt");

    if (file.is_open()) {
        file >> budget;
        file.close();
    } else {
        std::cout << "Budget file not found, using default budget.\n";  // Use std::cout
        budget = 1000.00;  // Default budget
    }

    return budget;
}

void saveBudget(double budget) {
    std::ofstream file("data/budget.txt");
    if (file.is_open()) {
        file << budget;
        file.close();
    } else {
        std::cerr << "Failed to open budget file.\n";  // Use std::cerr for error messages
    }
}

void saveCategoryBudgets(CategoryBudget categoryBudgets[], int numCategoryBudgets) {
    std::ofstream file("data/category_budgets.txt");
    if (file.is_open()) {
        for (int i = 0; i < numCategoryBudgets; ++i) {
            file << categoryBudgets[i].category << " "
                 << categoryBudgets[i].subCategory << " "
                 << categoryBudgets[i].monthlyLimit << "\n";
        }
        file.close();
    } else {
        std::cerr << "Failed to save category budgets.\n";  // Use std::cerr for error messages
    }
}

double getCategoryBudgetLimit(CategoryBudget categoryBudgets[], int numCategoryBudgets, const std::string& category, const std::string& subCategory) {
    for (int i = 0; i < numCategoryBudgets; ++i) {
        if (categoryBudgets[i].category == category && categoryBudgets[i].subCategory == subCategory) {
            return categoryBudgets[i].monthlyLimit;
        }
    }
    return 0.0;  // If no budget found for the category/subcategory, return 0
}
