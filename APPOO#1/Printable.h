#ifndef Printable_H
#define Printable_H

using namespace std;

class Printable{
public:
    virtual ostream& print(string type, string hp) = 0;
};
#endif
