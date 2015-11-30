#ifndef CUBE_H
#define CUBE_H
#include "solid.h"
#include <iostream> 		//need std::cout

class Cube : public Solid{
  float _s;  		// private: side lenght
public: 
  Cube (float s, float d)    // constructor definition (inline)
  : _s {s},                  // member variable initialization
    Solid {d}                // base class initialization
  { 
      std::cout << "Cube Constructor\n"; 
  }	
  ~Cube() {                        	// destructor definition (inline)
      std::cout << "Cube Destructor\n";
  }
  Cube (const Cube& c)    //copy constructor
  : Solid {c}             //init Solid part
  {
     _s = c._s;
     std::cout << "Cube Copy Constructor\n"; 
  }
  Cube& operator=(const Cube& c)
  {
     if(this==&c)
        return *this;
     Solid::operator=(c);
     _s = c._s;
     std::cout << "Cube Assignment Operator\n"; 
     return *this;
  }
  void Print(ostream& where)
  {
     where << "Cube with density " << _s << " and side length " << _d;
  }
  float CalcMass() const		//member function (inline)
  { 
      return _s*_s*_s*_d; 
  }
};



#endif //CUBE_H

