#ifndef Army_H
#define Army_H
#include <string>
#include "ArmyStatus.h"



using namespace std;

class Army: public IArmyStatus{
protected:

     vector<shared_ptr<AtackUnit>> Units {} ;

public:

    virtual void addUnit(const shared_ptr<AtackUnit> &U) override
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
/*
void printBuy()
{

    for (auto i : this->Units)
        {
            (*i).print(); cout<<"---"; cout<<endl;
        }
};
*/
virtual bool isAlive() override
{
    for (auto i : this->Units)
    {
        if ((*i).currentHP() > 0)
            {return true;}
    }
        return false;
}

void update()
{
auto i = begin(this->Units);
while (i != end(this->Units))
    {
    if ((**i).currentHP() <= 0)
    {
        i=this->Units.erase(i);
    }
    else
    {
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

#endif
