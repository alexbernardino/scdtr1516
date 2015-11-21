#ifndef SOLID_H
#define SOLID_H
#include <iostream> //need std::cout

class Solid {
protected: 	//must be used by subclasses
  float _d; 	
public:
  Solid( float d )  : _d {d}  {
      std::cout << "creating solid\n";
  }
  ~Solid()  {
     std::cout << "destroying solid\n";
  }
};
#endif // SOLID_H
