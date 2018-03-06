#ifndef Unit_H
#define Unit_H
#include <string>
#include "Vulnerable.h"
#include "Buyable.h"
#include "Atacking.h"

using namespace std;

class Unit: public IVulnerable,public IBuyable{

protected:
    int Cost;
    int HP;

public:

    virtual string getClass() = 0;

    float currentHP () {return HP;}

    void print(ostream&out){
    out<<"Unit: "<<getClass()<<endl;
    out<<"HP: "<<currentHP()<<endl;
    }

    void Heal(int Healed) {
    this->HP += Healed;}

    virtual int getCost () {return Cost;}

    void incCost (float incCost) {this->Cost += this->Cost*incCost;}
    void decCost (float decCost) {this->Cost -= this->Cost*decCost;}

    void printBuy(){
    cout<<"Unit: "+getClass();cout<<endl;cout<<"Cost: ";
    cout<<getCost();cout<<endl;

    }

    friend ostream& operator<<(ostream& out, Unit& U)
    {U.print(out);return out;}


    Unit(int HP,int Cost):HP(HP),Cost(Cost){}
    Unit() = default;
};


#endif
