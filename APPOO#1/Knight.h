#ifndef Knight_H
#define Knight_H
#include <string>


using namespace std;

bool getRand(int chance );

class Knight: public Unit {

private:

    static int const maxHP = 500;
    static int const blockChance = 3;

public:
    virtual void takeDamage(int dmg) override {
        if (getRand(blockChance)) {this->HP -= 0.5*dmg;}
        else {this->HP -= dmg;}

    }

    virtual float atack() override {
        return DPS;
    }

    virtual string getClass() override {
    return "Knight";
    }

    virtual int getMaxHP()override {
    return maxHP;
    }



    Knight():Unit(this->getMaxHP(),50,100){}



    friend ostream& operator<<(ostream& out, Knight& U)
    {U.print(out);return out;}


};


#endif
