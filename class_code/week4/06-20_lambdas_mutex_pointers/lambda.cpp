#include <vector>
#include <string>
#include <iostream>
#include<unordered_map>
#include<memory>
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
    auto it = remove_if(s.begin(), s.end(), 
                        [](char const &c){return !isalnum(c);});
    s.erase(it, s.end());
    
    string s_pali;
    for(auto iter = s.rbegin(); iter !=s.rend(); iter++) s_pali+=*iter;
    
    return s == s_pali;
}


void tempFunc(int value)
{
    cout<<"Hi: "<<value<<endl;
}


int main()
{
    typedef void(*func)(int);
    func p = tempFunc;
    cout<<"Here: ";
    p(3);

    // ) mutable {
    vector<int> values({7,4,8, 10, 81, 3});
    string x = "Hello: ";
    auto lambda = [x](int value){cout<<x<<value<<endl;};

    
    ForEach(values,lambda);
    ForEach(values, tempFunc);

}