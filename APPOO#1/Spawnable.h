#ifndef Spawnable_H
#define Spawnable_H


class ISpawnable{

public:

   virtual shared_ptr<ISpawnable> spawn(int delay) = 0;

};

#endif
