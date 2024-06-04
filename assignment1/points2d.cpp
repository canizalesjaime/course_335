// Do not change this file other than adding header files
// if needed.
// You can also comment parts of the functions, and uncomment
// as you add more functionality.
#include <points2d.h>

#include <array>
#include <iostream>
#include <string>
using namespace std;
using namespace teaching_project;

// Place stand-alone function in unnamed namespace.
namespace {
void TestPart1() {
    Points2D<int> a, b;  // Two empty Points2D are created.
    cout << a.size() << " " << b.size() << endl; // yields 0 0.
    const array<int, 2> a_point2{{7, 10}};
    Points2D<int> d{a_point2};  // A Points2D containing (7, 10) should be created.
    cout << d;  // Should just print (7, 10).
    cout << "Enter a sequence of points (integer)" << endl;
    cin >> a; // User enters a set of points in the form:
              // 3 7 4 3 2 1 10
              // The first 3 specifies number of points. Points are the triples
              // (7, 4), (3, 2), and (1, 10).
    cout << "Output1: " << endl;
    cout << a;  // Output should be what user entered.
    cout << "Enter a sequence of points (integer)" << endl;
    cin >> b; // Enter another sequence.
    cout << "Output2: " << endl;
    cout << b;
    Points2D<int> c{a};  // Calls copy constructor for c.
    cout << "After copy constructor1 c{a}: " << endl;
    cout << c;
    cout << a;
    a = b;  // Should call the copy assignment operator for a.
    cout << "After assignment a = b" << endl;
    cout << a;
    Points2D<int> e = move(c);  // Move constructor for e.
    cout << "After e = move(c) " << endl;
    cout << e;
    cout << c;
    cout << "After a = move(e) " << endl;
    a = move(e);  // Move assignment operator for a.
    cout << a;
    cout << e;
}

void TestPart2() {
    Points2D<double> a, b;
    cout << "Enter a sequence of points (double)" << endl;
    cin >> a; // User provides input for Points2D a.
    cout << a;
    cout << "Enter a sequence of points (double)" << endl;
    cin >> b; // User provides input for Points2D b.
    cout << b << endl;
    cout << "Result of a + b" << endl;
    cout << a + b << endl;
    Points2D<double> d = a + b;
    cout << "Result of d = a + b" << endl;
    cout << d;
    cout << "Second element in a: " << endl;
    cout << a[1][0] << ", " << a[1][1] << endl;  // Should print the 2nd element.
}

} // namespace

int main(int argc, char **argv) {
    TestPart1();
    TestPart2();
    return 0;
}