#ifndef UnitPrint_H
#define UnitPrint_H
#include "Unit.h"
using namespace std;

class UnitPrint{
private:

public:

    void print(Unit& U)
    {
            cout<<"Unit: "<<U.getClass()<<endl;
            cout<<"HP: "<<U.currentHP()<<endl;
    }

};

#endif
