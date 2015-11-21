#ifndef CYLINDER_H
#define CYLINDER_H
#include <iostream> //need std::cout

constexpr double PI {3.1415};          // needed to compute the area of the base

class Cylinder {
   float _r, _h, _d;                   // private:  radius, height and density, resp.
public: 
  Cylinder (float r, float h, float d) // constructor definition (inline)
  : _r {r}, _h {h}, _d {d}             // initialization of member variables C++11 style
  { 
      std::cout << "Creating Cylinder\n"; 
  }	
  ~Cylinder() {                        	// destructor definition (inline)
      std::cout << "Destroying Cylinder\n";
  }
  float CalcMass() 		//member function (inline)
  { 
      return PI*_r*_r*_h*_d; 
  }
};
#endif //CYLINDER_H

