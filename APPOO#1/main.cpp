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
        this->isRented = true;
    }
    void Return(int Damage = 0)
    {
        this->health -= Damage;
        this->isRented = false;
    }
    virtual double finalPrice() const = 0;

    virtual ~Vehicle() = default;

    virtual void print(ostream& out){}
    virtual void read(istream& in){}
    friend ostream& operator<<(ostream& out, Vehicle& V)
    {V.print(out);return out;}
    friend istream& operator>>(istream& in, Vehicle& V)
    {
     V.read(in); return in;
    }
};

};

class Bike : public Vehicle {

public:

    Bike() = default;
    Bike(bool Rented, int Taken, int HP, string brandName, double price,
         int weight, int gears):
         Vehicle(Rented,Taken,HP,brandName,price), weight(weight), gears(gears) {}
    double finalPrice() const override ;

    virtual void print(ostream& out)
{
    {
        cout<<"Type: Bike"<<endl;

        out<<"Number of times Taken "<<timesTaken<<endl;
        out<<"Health "<<health<<endl;
        out<<"Brand "<<Brand<<endl;
        out<<"Weight "<<weight<<endl;
        out<<"Gears "<<gears<<endl;
    }

    friend ostream& operator<<(ostream& out, Bike& M)
    {
        M.print(out);
        return out;
    }

    friend istream& operator<<(istream& out, Bike& M)
    {
        M.read(in);
        return in;
    }

}

    virtual void read(istream& in, Bike& C)
        {
            cout<<"Insert Bike data"<<endl;

                cout<<"Is the Bike Rented: ";in>>C.isRented;in.get();
                cout<<"How many times the bike was taken: ";in>>C.timesTaken;in.get();
                cout<<"Bike Health: ";in>>C.health;in.get();
                cout<<"Bike Brand: ";in>>C.brand;in.get();
                cout<<"Weight: ";in>>C.weight;in.get();
                cout<<"Gears: ";in>>C.gears;in,get();

        return in;
        }



protected:
    int weight;
    int gears;





    };

class Motorized : public Vehicle {

public:

    Motorized() = default;
    Motorized(bool Rented, int Taken, int HP, string brandName, double price,
              double Fuel):
              Vehicle(Rented, Taken, HP, brandName, price), fuelRating(Fuel) {}
    double finalPrice() const override;
    virtual double fuelCost() const;

        virtual void print(ostream& out)
{
        {
            cout<<"Type: Petrol Car"<<endl;

            out<<"Number of times Taken "<<timesTaken<<endl;
            out<<"Health "<<health<<endl;
            out<<"Brand "<<Brand<<endl;
            out<<"Fuel Rating"<<Fuel<<endl;
        }

            virtual void read(istream& in, Bike& C)
        {
            cout<<"Insert Petrol Car data"<<endl;

                cout<<"Is the Car Rented: ";in>>C.isRented;in.get();
                cout<<"How many times the Car was taken: ";in>>C.timesTaken;in.get();
                cout<<"Car Health: ";in>>C.health;in.get();
                cout<<"Car Brand: ";in>>C.brand;in.get();
                cout<<"Fuel Rating: ";in>>C.weight;in.get();

        return in;
        }


        friend ostream& operator<<(ostream& out, Motorized& M)
    {
        M.print(out);
        return out;
    }
        friend istream& operator<<(istream& out, Motorized& M)
    {
        M.read(in);
        return in;
    }


}

protected:

    double fuelRating;



};

class Electric : public Motorized{

public:

    Electric() = default;
    Electric(bool Rented, int Taken, int HP, string brandName, double price,
              double Fuel):
              Motorized(Rented, Taken, HP, brandName, price, Fuel) {}
    double finalPrice() const override;
    virtual double fuelCost() const override;

        virtual void print(ostream& out)
{
        {
            cout<<"Type: Electric Car"<<endl;

            out<<"Number of times Taken "<<timesTaken<<endl;
            out<<"Health "<<health<<endl;
            out<<"Brand "<<Brand<<endl;
            out<<"Fuel Rating"<<Fuel<<endl;
        }

                    virtual void read(istream& in, Bike& C)
        {
            cout<<"Insert Petrol Car data"<<endl;

                cout<<"Is the Car Rented: ";in>>C.isRented;in.get();
                cout<<"How many times the Car was taken: ";in>>C.timesTaken;in.get();
                cout<<"Car Health: ";in>>C.health;in.get();
                cout<<"Car Brand: ";in>>C.brand;in.get();
                cout<<"Fuel Rating: ";in>>C.weight;in.get();

        return in;
        }

        friend ostream& operator<<(ostream& out, Electric& M)
    {
        M.print(out);
        return out;
    }
        friend istream& operator<<(istream& out, Electric& M)
    {
        M.read(in);
        return in;
    }

}

};



int main()
{
    vector<shared_ptr<Vehicle>> Vehicles;



}
