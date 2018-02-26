#include <iostream>
#include <string>
#include <random>
#include <memory>

using namespace std;

std::default_random_engine generator;

bool getRand(int chance ){


std::uniform_int_distribution<int> distribution(1,chance);
int dice_roll = distribution(generator);
if (dice_roll == chance)
    {return true;}
else
    {return false;}
}


class Unit{

protected:
    int HP;
    int DPS;
    int Cost;


public:
    virtual void takeDamage(int dmg) = 0;
    virtual float atack() = 0;
    virtual string getClass() = 0;
    float currentHP () {return HP;}
    int getCost () {return Cost;}
    virtual int getMaxHP () = 0 ;
    friend ostream& operator<<(ostream& out, Unit& U)
    {U.print(out);return out;}
    void print(ostream&out){
    out<<"Unit: "<<getClass()<<endl;
    out<<"HP: "<<currentHP()<<endl;
    }
    void printBuy(){
    cout<<"Unit: "+getClass();cout<<endl;cout<<"Cost: ";
    cout<<getCost();cout<<endl;

    }
    Unit(int HP, int DPS, int Cost):HP(HP),DPS(DPS),Cost(Cost){}
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
    Knight():Unit(this->getMaxHP(),50,100){}
    friend ostream& operator<<(ostream& out, Knight& U)
    {U.print(out);return out;}




};

class Blademaster: public Unit{

private:
    static int const maxHP = 500;
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
    Blademaster():Unit(this->getMaxHP(),50,100){}
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

void printBuy(){

for (auto i : this->Units)
{
(*i).printBuy(); cout<<"---"; cout<<endl;
}
};

bool isAlive(){
    for (auto i : this->Units)
{
if ((*i).currentHP() > 0) {return true;}
}
return false;
}

void update(){
auto i = begin(this->Units);
while (i != end(this->Units)){
    if ((**i).currentHP() <= 0)
    {
        i=this->Units.erase(i);
    }
    else{
        ++i;
    }
}
}

float totalDmg ()
{
float total = 0;
for (auto i : this->Units)
{
total += (*i).atack();
}
return total;
}

void takeDmg(int dmg){
auto i = *(this->Units.end()-1);
(*i).takeDamage(dmg);
}


Army() = default;
};

int fight(Army& A1, Army& A2)
{
    float dmg1,dmg2;

    while (true)
    {
        dmg1 = A1.totalDmg();
        dmg2 = A2.totalDmg();
        A1.takeDmg(dmg2);
        A2.takeDmg(dmg1);
        A1.update();
        A2.update();
        cout<<"---------"<<endl;
        cout<<"Current situation on the battlefield"<<endl;
        cout<<A1<<endl;
        cout<<A2<<endl;

        if (!A1.isAlive() and !A2.isAlive())
        {
            return 1;
        }
        if (!A1.isAlive())
        {
            return 2;
        }
        if (!A2.isAlive())
        {
            return 3;
        }


    }
}

void armyBuild(Army&A,Army& Sample, int& Gold)
{
    int choice;
    while (Gold > 0)
    {
        cout<<"-------------------------------------"<<endl;
        cout<<"Current Army: "<<endl;cout<<A<<endl;
        cout<<"Gold Available: "<<Gold<<endl;
        cout<<"Units Available: "<<endl;
        cout<<"---"<<endl;
        Sample.printBuy();
        cout<<"Select unit to add: "<<endl;
        cin>>choice; cin.get();
        if (choice==1)
        {
            A.addUnit(make_shared<Knight>());
        }
        else
        {
            A.addUnit(make_shared<Blademaster>());
        }
        Gold -= 100;


    }
    return;
}

void autoBuild(Army& A, int Gold)
{
    while (Gold>0){
        if (getRand(2))
    {
        A.addUnit(make_shared<Knight>());
    }
        else
    {
        A.addUnit(make_shared<Blademaster>());
    }
        Gold -= 100;
                  }
}

int main()
{
   int Gold = 300;
   int rez;
   Army ArmyU1;
   Army ArmyU2;
   Army sampleArmy;
   sampleArmy.addUnit(make_shared<Knight>());
   sampleArmy.addUnit(make_shared<Blademaster>());
   cout<<"Welcome to Fighting Tournament"<<endl;
   cout<<"Build your Army"<<endl;
   armyBuild(ArmyU1,sampleArmy,Gold);
   autoBuild(ArmyU2,300);
   cout<<"-------------------------------------"<<endl;
   cout<<"Your army: "<<endl;
   cout<<ArmyU1<<endl;
   cout<<"Enemy Army: "<<endl;
   cout<<ArmyU2<<endl;
   rez=fight(ArmyU1, ArmyU2);
   if(rez == 1)
   {
       cout<<"It's a draw"<<endl;
   }
   else if(rez == 2)
   {
       cout<<"You lost"<<endl;
   }

   else if (rez == 3)
   {
       cout<<"Congratulations"<<endl;
   }
   cin.get();
   return 0;

}

