#ifndef Atacking_H
#define Atacking_H

using namespace std;

class IAtacking{

public:
    virtual float atack() = 0;
    virtual int getBaseDPS() = 0;
    virtual void incDPS(float incDPS) = 0;
    virtual void decDPS(float decDPS) = 0;

};

#endif
