#ifndef AtackUnit_H
#define AtackUnit_H
#include "Unit.h"
#include "Atacking.h"
#include "Unit.cpp"
#include "Spawnable.h"

using namespace std;

class AtackUnit: public Unit, public IAtacking, public ISpawnable{

protected:
        int DPS;

public:

    void incDPS(float incDPS) {this->DPS += this->DPS*incDPS;}
    void decDPS(float decDPS) {this->DPS -= this->DPS*decDPS;}

  /*  friend ostream& operator<<(ostream& out, AtackUnit& U)
    {U.print(out);return out;} */

    AtackUnit(int HP, int Cost, int DPS):Unit(HP,Cost),DPS(DPS){}
    AtackUnit() = default;

    friend class Shrine;
};

#endif
