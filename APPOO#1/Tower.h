#ifndef Tower_H
#define Tower_H

using namespace std;

class Tower: public DPSStructure{

private:

    int HP = 100;
    int GroundDPS = 200;
    int AirDPS = 50 ;

public:

    void setGroundDPS(int DPS){
        this->GroundDPS = DPS;
    }

    void setAirDPS(int DPS){
        this->AirDPS = DPS
    }

    virtual int getAverageDPS() override{
        avg = (this->GroundDPS+this->AirDPS)/2;
        return avg;
    }

};

#endif
