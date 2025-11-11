#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "expenditure.h"
#include "budget.h"

// Functions to load and save expenditures and budget
void loadExpenditures(Expenditure expenditures[], int& numExpenditures);
void saveExpenditures(Expenditure expenditures[], int numExpenditures);
double loadBudget();
void loadCategoryBudgets(CategoryBudget categoryBudgets[], int& numCategoryBudgets);
void saveCategoryBudgets(CategoryBudget categoryBudgets[], int numCategoryBudgets);

#endif // FILEHANDLER_H
