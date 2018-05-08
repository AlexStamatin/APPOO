#ifndef Building_H
#define Building_H

using namespace std;

class Building
{

protected:
    int HP;
    ISpawnable& unit;
public:

    void takeDamage(int dmg)
    {this->HP -= dmg;}


    shared_ptr<ISpawnable> train(int delay) {
        return unit.spawn(delay);
    }

    Building(int HP,ISpawnable& unit):HP(HP),unit(unit){}
    Building() = default;




};

#endif
