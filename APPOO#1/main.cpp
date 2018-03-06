#include <iostream>
#include <string>
#include <random>
#include <memory>
#include <chrono>
#include <thread>
#include "Unit.h"
#include "Knight.h"
#include "Blademaster.h"
#include "Army.h"
#include "Vulnerable.h"


using namespace std;

default_random_engine generator;

bool getRand(int chance )
{

//Returns True 1 in chance times

uniform_int_distribution<int> distribution(1,chance);
int dice_roll = distribution(generator);
if (dice_roll == chance)
    {return true;}
else
    {return false;}
}



int fight(Army& A1, Army& A2)
{
    float dmg1,dmg2;

    while (true)
    {
        dmg1 = A1.totalDmg();
        dmg2 = A2.totalDmg();
        A1.takeDmg(dmg2);
        A2.takeDmg(dmg1);
        A1.update();
        A2.update();
        cout<<"---------"<<endl;
        cout<<"Current situation on the battlefield"<<endl;
        cout<<"Your Army: "<<endl;
        cout<<A1<<endl;
        cout<<"Enemy Army: "<<endl;
        cout<<A2<<endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        if (!A1.isAlive() and !A2.isAlive())
        {
            return 1;
        }
        if (!A1.isAlive())
        {
            return 2;
        }
        if (!A2.isAlive())
        {
            return 3;
        }


    }
}

void armyBuild(Army&A,Army& Sample, int& Gold)
{
    int choice;
    while (Gold > 0)
    {
        cout<<"-------------------------------------"<<endl;
        cout<<"Current Army: "<<endl;cout<<A<<endl;
        cout<<"Gold Available: "<<Gold<<endl;
        cout<<"Units Available: "<<endl;
        cout<<"---"<<endl;
        Sample.printBuy();
        cout<<"Select unit to add: "<<endl;
        cin>>choice; cin.get();
        if (choice==1)
        {
            A.addUnit(make_shared<Knight>());
        }
        else
        {
            A.addUnit(make_shared<Blademaster>());
        }
        Gold -= 100;


    }
    return;
}

void autoBuild(Army& A, int Gold)
{
    while (Gold>0){
        if (getRand(2))
    {
        A.addUnit(make_shared<Knight>());
    }
        else
    {
        A.addUnit(make_shared<Blademaster>());
    }
        Gold -= 100;
                  }
}

int main()
{
   int Gold = 300;
   int rez;
   Army ArmyU1;
   Army ArmyU2;
   Army sampleArmy;
   sampleArmy.addUnit(make_shared<Knight>());
   sampleArmy.addUnit(make_shared<Blademaster>());
   cout<<"Welcome to Bloody Tournament"<<endl;
   cout<<"Build your Army"<<endl;
   armyBuild(ArmyU1,sampleArmy,Gold);
   autoBuild(ArmyU2,300);
   cout<<"-------------------------------------"<<endl;
   cout<<"Your army: "<<endl;
   cout<<ArmyU1<<endl;
   cout<<"Enemy Army: "<<endl;
   cout<<ArmyU2<<endl;
   cout<<"Press Enter to attack enemy army"<<endl;
   cin.get();
   rez=fight(ArmyU1, ArmyU2);
   if(rez == 1)
   {
       cout<<"It's a draw"<<endl;
   }
   else if(rez == 2)
   {
       cout<<"You lost"<<endl;
   }

   else if (rez == 3)
   {
       cout<<"Congratulations! You Win !"<<endl;
   }
   cin.get();
   return 0;

}

