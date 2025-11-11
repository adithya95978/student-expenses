#ifndef REPORT_H
#define REPORT_H

#include "expenditure.h"
#include "budget.h"

void generateReport(Expenditure expenditures[], int numExpenditures, double globalBudget, CategoryBudget categoryBudgets[], int numCategoryBudgets);

#endif // REPORT_H
