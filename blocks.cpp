#include <iostream> //need std::cout
using namespace std;
#include "cube.h"
#include "cylinder.h"

//declaration and definition of global function
float TotalMass(Solid *sptr[]) //receives an array of pointers to Solids
{
   float mass {0.0};
   while( *sptr != nullptr )
      mass += (*sptr++)->CalcMass();
   return mass;
}

int main() 
{
  Solid *svect[10];
  svect [0] = new Cube(1.25,1.0);
  svect [1] = new Cube(1.0,0.9);
  svect [2] = new Cylinder(1,1,0.9);
  svect [3] = new Cylinder(0.5,2,1.0);
  svect [4] = new Cube(1.25,1.0);
  svect [5] = new Cylinder(1,2,0.8);
  svect [6] = new Cylinder(1,0.5,0.7);
  svect [7] = new Cylinder(3,2,1.1);
  svect [8] = svect[9] = nullptr;
  float tot = TotalMass(svect);
  cout << "Total Mass: " << tot << endl;
  for(int i=0; svect[i]!=nullptr; i++) 
     delete svect[i]; 
}

//compile with g++ -std=c++11 -o blocks blocks.cpp
