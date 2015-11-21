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
      std::cout << "Creating Cube\n"; 
  }	
  ~Cube() {                        	// destructor definition (inline)
      std::cout << "Destroying Cube\n";
  }
  float CalcMass() 		//member function (inline)
  { 
      return _s*_s*_s*_d; 
   }
};
#endif //CUBE_H

