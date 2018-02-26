#include <iostream>
#include <string>
#include <random>
#include <memory>

using namespace std;

bool getRand(int chance){

std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(1,chance);
int dice_roll = distribution(generator);

if (dice_roll == chance)
    {return true ;}
else
    {return false;}
}


class Unit{

protected:
    int HP;
    int DPS;


public:
    virtual void takeDamage(int dmg) = 0;
    virtual float atack() = 0;
    virtual string getClass() = 0;
    float currentHP () {return HP;}
    virtual int getMaxHP () = 0 ;
    friend ostream& operator<<(ostream& out, Unit& U)
    {U.print(out);return out;}
    void print(ostream&out){
    out<<"Unit: "<<getClass()<<endl;
    out<<"HP: "<<currentHP()<<endl;
    }
    Unit(int HP, int DPS):HP(HP),DPS(DPS){}
};






class Knight: public Unit {

private:
    static int const maxHP = 500;
    static int const blockChance = 3;

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


public:
    Knight():Unit(this->getMaxHP(),50){}
    friend ostream& operator<<(ostream& out, Knight& U)
    {U.print(out);return out;}




};

class Blademaster: public Unit{

private:
    static int const maxHP;
    static int const critChance = 3;
    static int const critMulti = 2;

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


public:
    Blademaster():Unit(this->getMaxHP(),50){}
    friend ostream& operator<<(ostream& out, Blademaster& U)
    {U.print(out);return out;}



};

class Army{
protected:
     vector<shared_ptr<Unit>> Units {} ;

public:

    void addUnit(const shared_ptr<Unit> &U)
    {
     this->Units.push_back(U);
    }

friend ostream& operator<<(ostream& out, Army& A)
{
for (auto i : A.Units)
{
out<<*i;
}
return out;
};

Army() = default;
};



int main()
{
   Army ArmyU1;
   ArmyU1.addUnit(make_shared<Knight>());
      ArmyU1.addUnit(make_shared<Knight>());
         ArmyU1.addUnit(make_shared<Knight>());
            ArmyU1.addUnit(make_shared<Knight>());
   Knight K1;
   cout<<ArmyU1<<endl;
   return 0;
}

