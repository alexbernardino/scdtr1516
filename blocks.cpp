#include <iostream> //need std::cout
using namespace std;
#include "cube.h"
#include "cylinder.h"

int main() 
{
  Cylinder obj1 {2.0,1.0,0.9};
  Cube obj2 {3.0,0.9};

  float m1 = obj1.CalcMass();
  float m2 = obj2.CalcMass();
  float M = m1+m2;
  cout << "Total Mass " << M << endl;
}

