#ifndef Peasant_H
#define Peasant_H
#include "Unit.h"


using namespace std;

class Peasant: public Unit{
private:

    static int const maxHP = 1000;

public:

    virtual void takeDamage(int dmg) override  {this->HP -= dmg;}
    virtual string getClass() override { return "Peasant";}
    virtual int getMaxHP()override { return maxHP; }

    friend ostream& operator<<(ostream& out, Peasant& U)
    {U.print(out);return out;}

};

#endif
