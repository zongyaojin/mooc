#include <iostream>
using namespace std;

class A {
    int _a;
public:
    A(int a) : _a{a} {};
    void display() { cout << _a << endl; };
};

class B {
    int _b;
public:
    B(int b) : _b{b} {};
    void display() { cout << _b << endl; };
    void display_a(A a) {
        a.display();
    };
    void display_b(B bb) {
        bb._b = 1111;
        cout << bb._b << endl;
    }
};


int main() 
{
    A a(10);
    a.display();
    
    B b(1);
    B b2(100);
    b.display();
    b.display_a(a);
    b.display_b(b2);
    
	return 0;
}
