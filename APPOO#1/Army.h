#ifndef Army_H
#define Army_H
#include <string>



using namespace std;

class Army{
protected:

     vector<shared_ptr<AtackUnit>> Units {} ;

public:

    void addUnit(const shared_ptr<AtackUnit> &U)
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

void printBuy()
{

    for (auto i : this->Units)
        {
            (*i).printBuy(); cout<<"---"; cout<<endl;
        }
};

bool isAlive()
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
