#ifndef ABILITYCOMPARE_H
#define ABILITYCOMPARE_H
#include <vector>
#include <queue>
#include <iostream>
#include "wrestler.h"

using namespace std;
class abilityCompare
{
    public:
        bool operator()(const wrestler* lhs,const wrestler* rhs);

    private:
};

#endif // ABILITYCOMPARE_H
