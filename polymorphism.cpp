#include <iostream>
using namespace std;

// Polymorphism - Ability of objects to take many forms depending on the context in which it is used. It is of two types:
// 1. Compile-time polymorphism - Constructor overloading, function overloading and operator overloading.
// 2. Run-time polymorphism - Function overriding, virtual functions and abstract classes.

// Overloading - Multiple functions with same name in the same class.
// Overriding - Functions with the same name and same parameters but different implementation in different classes. Function of child class overrides the function of the parent class.

// Function overloading - Defining multiple functions with the same name but different parameters.
class Print {
public:
  void display(int a) {
    cout << "Integer: " << a << endl;
  }

  void display(char a) {
    cout << "Character: " << a << endl;
  }
};

// Function Overriding
class Parent {
public:
  void display() {
    cout << "Parent" << endl;
  }

  // Virtual function - A function that is declared in the base class to be redefined in the derived class and overrides base function. 
  // It is dynamic in nature and is resolved at run-time.
  virtual void show() {
    // Not a pure virtual function
    cout << "Virtual show function in parent class." << endl;
  }
};
class Child : public Parent {
public:
  void display() {
    cout << "Child" << endl;
  }
  void show() {
    cout << "Virtual show function in child class." << endl;
  }
};

// Abstract class - A class that has at least one pure virtual function. It is used to achieve abstraction.
// Pure virtual function - A virtual function that is declared in the base class and is assigned to 0. It is used to achieve abstraction.
// Abstract classes are used to provide a base class from which other classes can be derived and cannot be instantiated.
class Shape {
public:
  virtual void draw() = 0; // Pure virtual function
};
class Circle : public Shape {
public:
  void draw() {
    cout << "Drawing a circle." << endl;
  }
};

int main() {
  // Function Overloading
  Print p;
  p.display(5);
  p.display('A');

  // Function Overriding
  Child c;
  c.display();
  c.show(); // Function overriding using virtual function
  Parent p1;
  p1.display(); // Not due to function overriding

  // Abstract class
  // Shape s; // Error - Cannot instantiate an abstract class
  Circle c1;
  c1.draw(); // Function overriding using pure virtual function and abstract class.
}