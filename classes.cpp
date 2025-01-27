#include <iostream>
using namespace std;

// Four pillars of OOP:
// 1. Encapsulation - Wrapping up of data and methods into a single unit.
// 2. Abstraction - Hiding the implementation details and showing only the necessary details.
// 3. Inheritance - Inheriting the properties of a base class by the inherited class.
// 4. Polymorphism - Ability to take many forms. It is of two types:
//    a. Compile-time polymorphism - Function overloading and operator overloading.
//    b. Run-time polymorphism - Function overriding.

// Access specifiers - 
// 1. Public - Accessible from anywhere
// 2. Private - Accessible only within the class (Data hiding - abstraction)
// 3. Protected - Accessible within the class and inherited class

class Teacher {
private:
  double salary;
public:
  // Data members
  string name;
  string subject;
  string dept;

  // Constructor - Special member function that is called when an object is created.
  // It has the same name as the class and no return type.
  // It is automatically called when an object is created, if not defined then default constructor is called.
  // Always public
  // Memory allocation to objects is done by the constructor . Class doesn't occupy memory.
  // The three types of constructors are:
  // 1. Non-parameterized constructor
  // 2. Parameterized constructor
  // 3. Copy constructor
  // When multiple constructors are defined, it is called as constructor overloading. It is an example of polymorphism.

  // Non-parameterized constructor
  Teacher() {
    cout << "Constructor called!" << endl;
    dept = "Computer Science";
  }

  // Parameterized constructor
  // Teacher(string n, string s, string dep, double sal) {
  //   name = n;
  //   subject = s;
  //   salary = sal;
  //   dept = dep;
  //   // dep = dep; - Doesn't work.. Because the compiler gets confused between the parameter and the class attribute. To differentiate 'this' keyword comes into picture.
  // }

  Teacher(string name, string subject, string dept, double salary) {
    // this->prop = (*this).prop; - in terms of pointers
    this->name = name;
    this->subject = subject;
    this->salary = salary;
    this->dept = dept;
  }

  // Private attributes can be accessed and modified using public methods (member functions)
  // Setter method
  void changeSalary(double newSalary) {
    salary = newSalary;
  }

  // Getter method
  double getSalary() {
    return salary;
  }

  void getInfo() {
    cout << name << " teaches " << subject << " of department " << dept << " and earns " << getSalary() << endl;
  }
};

int main() {
  cout << "Hello, World!" << endl;

  // Object defined using Non-parameterized constructor
  Teacher t1; // Constructor called
  t1.name = "Mr. Sharma";
  t1.subject = "Maths";
  t1.changeSalary(50000);
  t1.getInfo();

  // Object defined using Parameterized constructor
  Teacher t2("Mr. Verma", "Physics", "Computer Science", 60000);
  t2.getInfo();

  Teacher t3(t2); // Default Copy constructor called
  t3.getInfo();

  return 0;
}


