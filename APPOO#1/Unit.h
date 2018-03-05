#ifndef Unit_H
#define Unit_H
#include <string>


using namespace std;

class Unit{

protected:

    int HP;
    int DPS;
    int Cost;


public:

    virtual void takeDamage(int dmg) = 0;
    virtual float atack() = 0;
    virtual string getClass() = 0;
    virtual int getMaxHP () = 0 ;

    float currentHP () {return HP;}
    int getCost () {return Cost;}

    void print(ostream&out){
    out<<"Unit: "<<getClass()<<endl;
    out<<"HP: "<<currentHP()<<endl;
    }
    void printBuy(){
    cout<<"Unit: "+getClass();cout<<endl;cout<<"Cost: ";
    cout<<getCost();cout<<endl;

    }

    friend ostream& operator<<(ostream& out, Unit& U)
    {U.print(out);return out;}


    Unit(int HP, int DPS, int Cost):HP(HP),DPS(DPS),Cost(Cost){}
    Unit() = default;
};


#endif
