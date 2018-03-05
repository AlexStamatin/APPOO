#ifndef Blademaster_H
#define Blademaster_H
#include <string>


using namespace std;


class Blademaster: public Unit{

private:

    static int const maxHP = 500;
    static int const critChance = 3;
    static int const critMulti = 2;
public:
    virtual void takeDamage(int dmg) override
    {this->HP -= dmg;}



    virtual float atack() override{

    if (getRand(critChance)) {return critMulti * DPS; }
    else {return DPS;}
    }


    virtual string getClass() override {
    return "Blademaster";
    }

    virtual int getMaxHP()override {
    return maxHP;
    }

    Blademaster():Unit(this->getMaxHP(),50,100){}

    friend ostream& operator<<(ostream& out, Blademaster& U)
    {U.print(out);return out;}



};

#endif
