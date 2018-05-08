#ifndef Tower_H
#define Tower_H
#include "Tower.h"

using namespace std;

class ChaosTower:public DPSStructure{

    int DPS;

public:

    virtual void setDPS(int DPS){
        int->DPS = DPS;
    }

    virtual int getAverageDPS(){
        return DPS;
    }

};

#endif
