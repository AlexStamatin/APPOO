#include <iostream>

using namespace std;

class Vehicle {

    friend istream& operator>>(istream&, Vehicle&);
    friend istream& operator<<(ostream&, Vehicle&);

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
        this->isRented = true;
    }
    void Return(int Damage = 0)
    {
        this->health -= Damage;
        this->isRented = false;
    }
    virtual double finalPrice() const = 0;

    virtual ~Vehicle() = default;
};

class Bike : public Vehicle {

friend istream& operator>>(istream&, Bike&);
friend istream& operator<<(ostream&, Bike&);

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

class Motorized : public Vehicle {

    friend istream& operator>>(istream&, Motorized&);
    friend istream& operator<<(ostream&, Motorized&);

public:

    Motorized() = default;
    Motorized(bool Rented, int Taken, int HP, string brandName, double price,
              double Fuel):
              Vehicle(Rented, Taken, HP, brandName, price), fuelRating(Fuel) {}
    double finalPrice() const override;
    virtual double fuelCost() const;

protected:

    double fuelRating;



};

class Electric : public Motorized{

    friend istream& operator>>(istream&, Electric&);
    friend istream& operator<<(ostream&, Electric&);

public:

    Electric() = default;
    Electric(bool Rented, int Taken, int HP, string brandName, double price,
              double Fuel):
              Motorized(Rented, Taken, HP, brandName, price, Fuel) {}
    double finalPrice() const override;
    virtual double fuelCost() const override;

};







int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
