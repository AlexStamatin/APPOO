#ifndef Vulnerable_H
#define Vulnerable_H

using namespace std;

class IVulnerable{

public:

    virtual void takeDamage(int dmg) = 0;
    virtual int getMaxHP() = 0;
    virtual float currentHP () = 0;
    virtual void Heal(int Healed) = 0;

    };


#endif
