#include <iostream>
using namespace std;

// Copy constructor - A constructor that copies attributes of one object to another object.
// There are two types of copies:
// 1. Shallow copy - Copies the address of the object to another object. Both objects point to the same memory location. Default copy constructor is a shallow copy.
// 2. Deep copy - Copies the value of the object attribute from a memory location to another object's attribute memory address. Both objects point to different memory locations.

// Destructor - A special member function that is automatically called when an object goes out of scope or is deleted. It is used to release resources acquired by the object. It has the same name as the class with a tilde (~) before it and no return type. It is called only once for an object.

// Rule of five - If you define any one of the following, then you should define all five:
// 1. Destructor
// 2. Copy constructor - It is used to copy the attributes of one object to another object.
// 3. Copy assignment operator
// 4. Move constructor - It is used to transfer resources from one object to another object.
// 5. Move assignment operator

class Person {
private:
    string species;
public:
    string name;
    int* agePtr;
    Person(string name, int age) {
        this->name = name;
        agePtr = new int;
        *agePtr = age;
    }

    // Person(Person &p) {
    //     cout << "Custom shallow copy constructor called!" << endl;
    //     name = p.name;
    //     this->agePtr = p.agePtr;
    // }

    Person(Person &p) {
        cout << "Custom deep copy constructor called!" << endl;
        name = p.name;
        agePtr = new int;
        *agePtr = *(p.agePtr);
    }

    // (Check) Move Constructor - checks if the object is an rvalue reference and then transfers the resources from one object to another object.
    Person(Person &&p) {
        cout << "Move constructor called!" << endl;
        name = p.name;
        agePtr = p.agePtr;
        p.agePtr = nullptr;
    }

    // Destructor - Only removes the value of the pointer and not the pointer itself. It still points to the memory location.
    ~Person() {
        cout << "Destructor called for " << name << endl;
        delete agePtr;
    }

    void display() {
        cout << name << " " << *agePtr << endl;
    }
};

int main() {
    // Try following by keeping one of the copy constructors commented and observer the output.

    Person p1("John", 25);
    p1.display();
    Person p2(p1);
    p2.display();
    *(p2.agePtr) = 30;
    p1.display();
    return 0;
}