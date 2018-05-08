#ifndef Shrine_H
#define Shrine_H

using namespace std;

class Shrine{

private:

    int HP = 1000;

public:

    void lvlup(AtackUnit& Unit){

    if (Unit.getClass() == "Knight"){

        Unit.Cost -= 10;
    }

    else if (Unit.getClass() == "Blademaster"){

        Unit.DPS += 20;
    }

    }


};

#endif
