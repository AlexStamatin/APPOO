#ifndef Blademaster_H
#define Blademaster_H
#include <string>
#include "AtackUnit.h"

using namespace std;


class Blademaster: public AtackUnit{

private:

    static int const maxHP = 500;
    static int const critChance = 3;
    static int const critMulti = 2;
    static int const BaseDPS = 50;
public:
    virtual void takeDamage(int dmg) override
    {this->HP -= dmg;}

    virtual int getBaseDPS() override {
    return BaseDPS;
    }

    virtual float atack() override{

    if (getRand(critChance)) {return critMulti * BaseDPS; }
    else {return BaseDPS;}
    }


    virtual string getClass() override {
    return "Blademaster";
    }

    virtual int getMaxHP()override {
    return maxHP;
    }

    Blademaster():AtackUnit(this->getMaxHP(),this->getBaseDPS(),100){}

 /*   friend ostream& operator<<(ostream& out, Blademaster& U)
    {U.print(out);return out;} */



};

#endif
