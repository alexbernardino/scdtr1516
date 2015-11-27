#include <iostream>
using namespace std;
class A {
public: 
   int a; 
   void f() {cout<<"A::f()"<<endl;};
   virtual int v() {cout<<"A::v()"<<endl;}; 
};
class B : public A {
public: 
   int b; 
   void f() {cout<<"B::f()"<<endl;};
   virtual int v()  {cout<<"B::v()"<<endl;};
};
class C : public B  {
public: 
   int c; 
   void f() {cout<<"C::f()"<<endl;}; 
   virtual int v() {cout<<"C::v()"<<endl;};
};

int main() {
   C c; 
   c.f();  
   c.B::f();  
   c.A::f();
   c.v();  
   c.B::v();  
   c.A::v(); 

   C *b = &c;
   b->C::f();  
   b->B::f();  
   b->A::f();
   b->C::v();  
   b->B::v();  
   b->A::v(); 
}       

