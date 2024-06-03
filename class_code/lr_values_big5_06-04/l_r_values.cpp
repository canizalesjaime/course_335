#include <iostream>
#include <string>

using namespace std;

int PrintString(string& s)
{
    cout<<"l value function "<<s<<endl;
    int x = 5;
    return x;
}

int & PrintString(string&& s)
{
    cout<<"r value function "<<s<<endl;
    int u = 4;
    return u;
}

int main()
{
    string s = "whatsup";
    PrintString(s);
    PrintString("all");
}