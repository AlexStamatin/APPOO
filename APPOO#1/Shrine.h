#ifndef Shrine_H
#define Shrine_H

using namespace std;

class Shrine{

private:

    int HP = 1000;

public:

    void lvlup(AtackUnit& Unit){

    Unit.lvlup();
    }


};

#endif
