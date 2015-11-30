#ifndef CYLINDER_H
#define CYLINDER_H

#include "solid.h"
#include <iostream> //need std::cout

constexpr double PI {3.1415};      // needed to compute the area of the base

class Cylinder : public Solid {    // inherit from Solid
   float _r, _h;                   // private:  radius, height
public: 
  Cylinder (float r, float h, float d)    // constructor definition (inline)
  : _r {r}, _h {h}, 	// member variable initialization
    Solid {d}           // base class initialization
  { 
      std::cout << "Cylinder Constructor\n"; 
  }	
  ~Cylinder() {                        	// destructor definition (inline)
      std::cout << "Cylinder Destructor\n";
  }
  float CalcMass() const		//member function (inline)
  { 
      return PI*_r*_r*_h*_d; 
  }
  void Print(ostream& where)
  {
     where << "Cylinder with density " << _d << ", radius " << _r << " and height " << _h;
  }
};
#endif //CYLINDER_H

