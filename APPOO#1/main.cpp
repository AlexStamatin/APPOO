#include <iostream>

using namespace std;

class Vehicle {

protected:

    bool isRented;
    int timesTaken;
    int health;
    string brand;
    double basePrice;

public:
    Vehicle() = default;
    Vehicle(bool Rented, int Taken, int HP, string brandName, double price):
            isRented(Rented), timesTaken(Taken), health(HP), brand(brandName), basePrice(price){}
    void Rent()
    {
        this->isRented = True;
    }
    void Return(int Damage = 0)
    {
        this->health -= Damage;
        this->isRented = False;
    }
    virtual int finalPrice() const = 0;

    virtual ~Vehicle() = default;
}

class Bike : public Vehicle {

friend istream& operator>>(istream&, Bike&)
friend istream& operator<<(ostream&, Bike&)

public:

    Bike() = default;
    Bike(bool Rented, int Taken, int HP, string brandName, double price,
         int weight, int gears):
         Vehicle(Rented,Taken,HP,brandName,price), weight(weight), gears(gears) {}
    double finalPrice() const override ;

protected:
    int weight;
    int gears;


    };

class Motorized : public Vehicle {};

class Electric : public Motorized{};











};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
