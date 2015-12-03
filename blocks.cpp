#include <iostream> //need std::cout
#include <memory>   //need std::unique_ptr
#include <vector>   //need std::vector
using namespace std;
#include "cube.h"
#include "cylinder.h"

//declaration and definition of global function
float TotalMass(Solid const * const sptr[]) //receives an array of pointers to Solids
//promise not to modify neither the pointers nor the solids
{
   float mass {0.0};
   while( *sptr != nullptr )
      mass += (*sptr++)->CalcMass();
   return mass;
}

float TotalMass(vector<unique_ptr<Solid>> &v) 
{
   float mass {0.0};
   //for(auto p = v.cbegin(); p != v.cend(); p++)
   //   mass += (*p)->CalcMass();

   for(auto &s : v)
      mass += s->CalcMass();
   return mass;
}

Cube func(Cube c)
{
   return Cube {c};
}


void f1(shared_ptr<Solid> p) { 
    //p is a local copy – increments ref count 
    cout << *p << endl;
}   //p destroyed – decrements ref count



int main() 
{
  vector<unique_ptr<Solid>> sv;
  constexpr int max_elems {10};
  sv.reserve(max_elems);
  
  using T = unique_ptr<Solid>; //type alias

  sv.push_back( T {new Cube {1.25,1.0}} );
  // same as sv[0] =  T new Cube{1.25,1.0};
  sv.push_back( T {new Cube {1.0,0.9}} );
  sv.push_back( T {new Cylinder {0.5,2.0,1.0}} );
  sv.push_back( T {new Cube {1.25,1.0}} );
  sv.push_back( T {new Cylinder {1.0,2.0,0.8}} );
  sv.push_back( T {new Cylinder {1.0,0.5,0.7}} );
  sv.push_back( T {new Cylinder {3.0,2.0,1.1}} );

  float tot = TotalMass(sv);
  cout << "Total Mass: " << tot << endl;
} //sv goes out of scope, all objects released safely

//compile with g++ -std=c++11 -o blocks blocks.cpp
