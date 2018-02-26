#include <iostream>
#include <string>
#include <random>

using namespace std;

bool getRand(int chance){

std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(1,chance);
int dice_roll = distribution(generator);

if (dice_roll == chance) {return true ;}
else {return false;}
}


class Unit{

private:
    int HP;
    int DPS;


public:
    virtual void takeDamage(int dmg) = 0;
    virtual float atack() = 0;
    virtual string getClass() = 0;
    float currentHP () {return HP;}
    virtual int getMaxHP () = 0 ;
    virtual void print(ostream& out){}
    friend ostream& operator<<(ostream& out, Unit& U)
    {U.print(out);return out;}
    virtual void print(ostream&out){
    cout<<"Unit: "<<getClass()<<endl;
    cout<<"HP: "<<currentHP()<<endl;
    }
};




};

class Knight: public Unit {

private:
    static int maxHP = 500;
    static int blockChance = 3;

    virtual void takeDamage(int dmg) override {
        if getRand(blockChance) {this->HP -= 0.5*dmg;}
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
    Knight():HP(this.getMaxHP()),DPS(50){}
    friend ostream& operator<<(ostream& out, Knight& U)
    {U.print(out);return out;}




};

class Blademaster: public Unit{

private:
    static int maxHP;
    static int critChance = 3;
    static int critMulti = 2;

    virtual void takeDamage(int dmg) override
    {this->HP -= dmg;}

    }

    virtual float atack() override{

    if getRand(critChance) {return critMulti * DPS; }
    else {return DPS;}
    }

        return DPS;


    virtual string getClass() override {
    return "Blademaster";
    }

    virtual int getMaxHP()override {
    return maxHP;
    }


public:
    Blademaster():HP(this.getMaxHP()),DPS(50){}
        friend ostream& operator<<(ostream& out, Knight& U)
    {U.print(out);return out;}



};

class Army




int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
