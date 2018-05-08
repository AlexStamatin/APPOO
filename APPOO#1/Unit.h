#ifndef Unit_H
#define Unit_H
#include <string>
#include "Vulnerable.h"
#include "Buyable.h"
#include "Atacking.h"
#include "Printable.h"
#include "Spawnable.h"
using namespace std;

class Unit: public IVulnerable,public IBuyable{

protected:
    int Cost;
    int HP;

public:

    virtual string getClass() = 0;

    float currentHP ();

    void Heal(int Healed);

    virtual int getCost ();

    void incCost (float incCost);
    void decCost (float decCost);

    virtual void lvlup() = 0;

    friend ostream& operator<<(ostream& out, Unit& U);


    Unit(int HP,int Cost);
    Unit();
};


#endif
