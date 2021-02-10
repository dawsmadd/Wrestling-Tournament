#include <vector>
#include <queue>
#include <iostream>
#include "abilityCompare.h"
using namespace std;

bool abilityCompare::operator()(const wrestler* lhs,const wrestler* rhs)
{
    return ((lhs->getAbility())<(rhs->getAbility()));
}
