#include<iostream>

using namespace std;

void point2d(int x=3, int y=4); // function declaration

void f(int a, int b, int c); // f() has no defaults
void f(int a, int b, int c = 1); // c is given a default
void f(int a = 1, int b, int c); // a is given a default
void f(int a, int b = 1, int c); // b is given a default

int main()
{
    f(7,2,3); // function call
    f(8,2);
    f(9);
    f();
    return 0;
}

void point2d(int x, int y) // function definition
{
    cout<<x<<" "<<y<<endl;
}

void f( int a, int b, int c)
{
    cout<<a<<" "<<b<<" "<<c<<endl;
}
