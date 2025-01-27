#include <iostream>
using namespace std;

// Constructor is always called for the parent class first and then for the child class. However, the destructor is called in the reverse order.
// If the parent class has a parameterized constructor, then the child class should have a parameterized constructor as well.
// If the parent class has a non-parameterized constructor, then the child class can have a non-parameterized constructor or a parameterized constructor.

// Modes of inheritance:
// Base   ---   Private         Protected       Public
// Derived  
//    |
// Public       Not Inherited   Protected       Public
// Protected    Not Inherited   protected      Protected
// Private      Not Inherited   Private         Private

// Types of inheritance:
// 1. Single Level inheritance - One parent and one child class.
// 2. Multi-Level inheritance - One child has multiple levels of parent classes (like grand and great grand).
// Ex - class Student : public Person
//      class Person : public LivingBeing
// 3. Multiple inheritance - One child has multiple parent classes.
// Ex - class TeachAssist : public Teacher, public Student
// 4. Hierarchical inheritance - Multiple child classes inherit from one parent class.
// 5. Hybrid inheritance - Combination of multiple and multi-level inheritance.


class Person {
public:
  string name;
  int age;

  // If parameterized constructor defined in parent class.
  Person(string name, int age) {
    this->name = name;
    this->age = age;
  }
};

class Student : public Person {
public:
  int grade;
  string rollNo;

  // If parameterized constructor defined in parent class.
  Student(string name, int age, int grade, string rollNo) : Person(name, age) {
    this->grade = grade;
    this->rollNo = rollNo;
  }

  void display() {
    cout << "Name: " << name << ", Age: " << age << ", Grade: " << grade << ", Roll No: " << rollNo << endl;
  }
};

int main() {

  // If non-parameterized or default constructor defined in parent class.
  // Student s1;
  // s1.name = "John";
  // s1.age = 18;
  // s1.grade = 8;
  // s1.rollNo = "19CS029";
  // s1.display();

  // If parameterized constructor defined in parent class.
  Student s2("Jane", 18, 9, "19CS030");
  s2.display();

  return 0;
}