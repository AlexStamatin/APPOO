#ifndef Knight_H
#define Knight_H
#include <string>
#include "AtackUnit.h"

using namespace std;

bool getRand(int chance );

class Knight: public AtackUnit {

private:

    static int const maxHP = 500;
    static int const blockChance = 3;
    static int const BaseDPS = 50;

public:
    virtual void takeDamage(int dmg) override {
        if (getRand(blockChance)) {this->HP -= 0.5*dmg;}
        else {this->HP -= dmg;}

    }

    virtual int getBaseDPS() override {
    return BaseDPS;
    }

    virtual float atack() override {
        return BaseDPS;
    }

    virtual string getClass() override {
    return "Knight";
    }

    virtual int getMaxHP()override {
    return maxHP;
    }



    Knight():AtackUnit(this->getMaxHP(),this->getBaseDPS(),100){}



    friend ostream& operator<<(ostream& out, Knight& U)
    {U.print(out);return out;}


};


#endif
