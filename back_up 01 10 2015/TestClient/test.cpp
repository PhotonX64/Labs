#include "test.h"

Test::Test()
{
}

Test::~Test()
{

}

void Test::addQuest(Quest *pNew)
{
    this->arrQuest.append(pNew);
}

int Test::getCount()
{
    return this->arrQuest.size();
}

Quest *Test::getQuest(int index)
{
    return this->arrQuest[index];
}

