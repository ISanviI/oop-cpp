#include <iostream>
using namespace std;

// Polymorphism - Ability of objects to take many forms depending on the context in which it is used. It is of two types:
// 1. Compile-time polymorphism - Constructor overloading, function overloading and operator overloading.
// 2. Run-time polymorphism - Function overriding, virtual functions and abstract classes.

// Overloading - Multiple functions with same name in the same class.
// Overriding - Functions with the same name and same parameters but different implementation in different classes. Function of child class overrides the function of the parent class.

// Operator Overloading - Could be implemented using both friend functions and member functions.

// Function overloading - Defining multiple functions with the same name but different parameters.
class Print
{
public:
  void display(int a)
  {
    cout << "Integer: " << a << endl;
  }

  void display(char a)
  {
    cout << "Character: " << a << endl;
  }
};

// Function Overriding
// It is used for late binding, where the function to be called is determined at runtime based on the type of the object.
class Parent
{
public:
  void display()
  {
    cout << "Parent" << endl;
  }

  // Virtual function - Function declared in the base class to be redefined in the derived class and override base function.
  // It is dynamic in nature and is resolved at run-time.
  // Constructors and destructors can be virtual functions too.
  // It is uses VTABLE and VPTR mechanism to achieve dynamic binding.
  // VTABLE - A table that holds the addresses of virtual functions. Each class with virtual functions has its own VTABLE.
  // VPTR - A pointer that points to the VTABLE of the class. Each object of a class with virtual functions has its own VPTR.
  // To understand about it in detail, watch the video - https://youtu.be/47ZP-0iBicI by Keerti Purswani.
  virtual void show()
  {
    // Not a pure virtual function
    cout << "Virtual show function in parent class." << endl;
  }
};
class Child : public Parent
{
public:
  void display()
  {
    cout << "Child" << endl;
  }
  void show()
  {
    cout << "Virtual show function in child class." << endl;
  }
};

// Abstract class - A class that has at least one pure virtual function. It is used to achieve abstraction.
// Pure virtual function - A virtual function that is declared in the base class and is assigned to 0. It is used to achieve abstraction.
// Abstract classes are used to provide a base class from which other classes can be derived. The abstract class cannot be instantiated.
class Shape
{
public:
  virtual void draw() = 0; // Pure virtual function
};
class Circle : public Shape
{
public:
  void draw()
  {
    cout << "Drawing a circle." << endl;
  }
};

int main()
{
  // ### Function Overloading
  Print p;
  p.display(5);
  p.display('A');

  // ### Function Overriding
  Child c1;
  c1.display();
  c1.show(); // Function overriding using virtual function
  Parent p1;
  p1.display(); // Not due to function overriding

  // Early Binding (Static Binding / Compile-time Binding) vs Late Binding (Dynamic Binding / Run-time Binding)
  Child c2;
  Parent p2;

  Parent *ptr = &c2;
  // You might think how can a Child object be assigned to a Parent pointer?
  // This is possible because of inheritance. A Child object is also a Parent object.
  // This is called as UPCASTING.
  // DOWNCASTING is possible but is unsafe.
  ptr->display(); // Calls Parent::display() because 'display' is not virtual in Parent - EARLY BINDING
  // The compiler binds based on the pointer's type (Parent *), not the object's actual type.
  ptr->show(); // Calls Child::show() because 'show' is virtual in Base - LATE BINDING
  // The compiler binds based on the actual object type (Child), not the pointer's type.

  // ### Abstract class
  // Shape s; // Error - Cannot instantiate an abstract class
  Circle round;
  round.draw(); // Function overriding using pure virtual function and abstract class.
}