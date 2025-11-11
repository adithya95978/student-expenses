#ifndef BUDGET_H
#define BUDGET_H

#include "expenditure.h"

double loadBudget();
void saveBudget(double budget);
void saveCategoryBudgets(CategoryBudget categoryBudgets[], int numCategoryBudgets);
double getCategoryBudgetLimit(CategoryBudget categoryBudgets[], int numCategoryBudgets, const std::string& category, const std::string& subCategory);

#endif // BUDGET_H
 