#include <vector>
#include <string>
#include <iostream>
#include<algorithm>
#include<functional>

using namespace std;


//void(*func)(int)
void ForEach(const vector<int>& values, const function<void(int)>& func)
{
    for(int val : values)
        func(val);
}


bool isPalindrome(string s) 
{
    //convert s to all lowercase 
    for_each(s.begin(), s.end(),[](char& c){c = tolower(c);});
    
    //remove non-alphanumeric characters
    //does so by moving all nonalphanumeric character to end of string
    //then you must delete character from first invalid character located at
    //it and onwards
    auto it = remove_if(s.begin(), s.end(), 
                        [](char const &c){return !isalnum(c);});
    s.erase(it, s.end());
    
    string s_pali;
    for(auto iter = s.rbegin(); iter !=s.rend(); iter++) s_pali+=*iter;
    
    return s == s_pali;
}


void tempFunc(int value)
{
    cout<<"Hi: "<<value<<" ";
}


void tempFunc2(string value)
{
    cout<<"Hi: "<<value<<endl;
}


int main()
{
    typedef void(*func)(int);
    func p = tempFunc;
    void(*tempFunc2Ptr)(string) = tempFunc2;
    cout<<"Here: ";
    p(3);
    tempFunc2Ptr("sup");
 
    vector<int> values({7,4,8, 10, 81, 3});
    string x = "Hello: ";

    // ) mutable { modify capture variables.pass by copy =, pass by reference &
    auto lambda = [&x](int value){cout<<x<<value<<" ";};
    ForEach(values,lambda);
    cout<<endl;
    ForEach(values, tempFunc);
    cout<<endl;

    cout<<isPalindrome("Apple-Sauce")<<endl;
    cout<<isPalindrome("Race-c-ar-")<<endl;

    sort(values.begin(), values.end());
    x="";
    ForEach(values,lambda);
    cout<<endl;

    sort(values.begin(),values.end(),[](int a, int b){return a > b;});
    ForEach(values,lambda);
    return 0;
}