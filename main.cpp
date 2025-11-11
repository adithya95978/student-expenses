#include <iostream>
#include "expenditure.h"
#include "budget.h"
#include "report.h"
#include "fileHandler.h"

int main() {
    Expenditure expenditures[100]; // Array to store expenditures
    int numExpenditures = 0; // Number of expenditures
    double budget = loadBudget(); // Load global budget from file
    CategoryBudget categoryBudgets[100]; // Array to store category budgets
    int numCategoryBudgets = 0; // Number of category budgets

    // Load expenditures from file
    loadExpenditures(expenditures, numExpenditures);

    int choice;
    double total = 0; // Declare total before the switch statement to avoid scope issues

    do {
        std::cout << "\n--- Student Expenditure Tracker ---\n";
        std::cout << "1. Add Expenditure\n";
        std::cout << "2. Show Report\n";
        std::cout << "3. Calculate Total Expenditure\n";
        std::cout << "4. Set Budget for a Category/Subcategory\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // Add a new expenditure
                Expenditure newExpenditure;
                std::cout << "Enter category: ";
                std::cin >> newExpenditure.category;
                std::cout << "Enter sub-category: ";
                std::cin >> newExpenditure.subCategory; // Take sub-category input
                std::cout << "Enter amount: ";
                std::cin >> newExpenditure.amount;
                std::cout << "Enter date (YYYY-MM-DD): ";
                std::cin >> newExpenditure.date;
                std::cin.ignore();  // Ignore newline character from previous input
                std::cout << "Enter description: ";
                std::getline(std::cin, newExpenditure.description); // Take description input

                expenditures[numExpenditures++] = newExpenditure;  // Add to array

                // Save expenditure to file
                saveExpenditures(expenditures, numExpenditures);
                break;
            }
            case 2:
                // Show report
                generateReport(expenditures, numExpenditures, budget, categoryBudgets, numCategoryBudgets);
                break;
            case 3:
                // Calculate total expenditure
                total = calculateTotalExpenditure(expenditures, numExpenditures);
                std::cout << "Total Expenditure: " << total << std::endl;
                break;
            case 4: {
                // Set budget for category/subcategory
                CategoryBudget newBudget;
                std::cout << "Enter category: ";
                std::cin >> newBudget.category;
                std::cout << "Enter sub-category: ";
                std::cin >> newBudget.subCategory;
                std::cout << "Enter monthly budget limit: ";
                std::cin >> newBudget.monthlyLimit;

                categoryBudgets[numCategoryBudgets++] = newBudget; // Save budget

                // Save category budget to file
                saveCategoryBudgets(categoryBudgets, numCategoryBudgets);
                break;
            }
            case 5:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
