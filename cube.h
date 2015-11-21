#ifndef CUBE_H
#define CUBE_H
#include <iostream> 		//need std::cout

class Cube{
  float _s, _d;  		// private: side lenght and material density, resp.
public: 
  Cube (float s, float d) 	// constructor definition (inline)
  : _s {s}, _d{d}                       	// initialization of member variables C++11 style
  { 
      std::cout << "Creating Cube\n"; 
  }	
  float CalcMass() 		//member function (inline)
  { 
      return _s*_s*_s*_d; 
   }
};
#endif //CUBE_H

