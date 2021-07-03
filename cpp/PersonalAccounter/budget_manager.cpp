#include <algorithm>
#include <vector>
#include "budget_manager.h"

void BudgetManager::ComputeIncome(const Date& from, const Date& to)
{

}

void BudgetManager::Earn(const Date& from, const Date& to, 
                        const double& value)
{
    std::vector <int> v;
    std::partial_sum(v.begin(), v.end(),v.begin());
}
