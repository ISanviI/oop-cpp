#include <iostream>
using namespace std;

// Static Variables - Declared as static in a function and initialized only once for the lifetime of the program.
void fun() {
  int a = 10;
  static int b = 10;
  a++;
  b++;
  cout << "a: " << a << ", b: " << b << endl;
}

// Static variables in a class - created only once for the class and not for each object. They are shared among all objects of the class.
class Test {
public:
  static int count;
  void incCount() {
    count = count + 1;
  }
};
int Test::count = 1; // Always declared after class definition, but variable declared inside class.

// Static objects
class ABC {
public:
  ABC() {
    cout << "Constructor called!" << endl;
  }
  ~ABC() {
    cout << "Destructor called!" << endl;
  }
};

int main() {
  // Static variables example
  fun();
  fun();
  fun();
  // cout << "b : " << b << endl; - Static variable not accessible in a different function.

  // Static variables in a class example
  Test t1, t2;
  cout << Test::count << endl;
  cout << t1.count << endl;
  cout << t2.count << endl;
  t1.incCount();
  cout << t1.count << endl;
  cout << t2.count << endl;

  // Static objects example
  if (true) {
    // Try each of the folllowing statements one by one and see the output.
    ABC obj1;
    // static ABC obj2;
  }
  cout << "End of main! Verify with static object." << endl;

  return 0;
}