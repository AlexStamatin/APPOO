#ifndef Buyable_H
#define Buyable_H


using namespace std;

class IBuyable{

public:
    virtual int getCost () = 0;
    virtual void incCost (float incCost) = 0;
    virtual void decCost (float decCost) = 0;

};

#endif
