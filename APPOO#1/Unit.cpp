#include "Unit.h"
#include <string>
#include "Vulnerable.h"
#include "Buyable.h"
#include "Atacking.h"
#include "Printable.h"
#include "UnitPrint.h"

using namespace std;


    float Unit::currentHP () {return HP;}

    void Unit::Heal(int Healed) {
    this->HP += Healed;}

    int Unit::getCost () {return Cost;}

    void Unit::incCost (float incCost) {this->Cost += this->Cost*incCost;}
    void Unit::decCost (float decCost) {this->Cost -= this->Cost*decCost;}


    ostream& operator<<(ostream& out, Unit& U)
    {
        UnitPrint Printer;
        Printer.print(U);
    }


    Unit::Unit(int HP,int Cost):HP(HP),Cost(Cost){}
    Unit::Unit() = default;



