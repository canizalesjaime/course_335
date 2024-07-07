#include<iostream>
#include<string>

using namespace std;


long long encode1 ( const int RADIX, const string & s)
{
    long long hashval = 0;
    for (int i = 0; i < s.length(); i++)
        hashval = s[i] + RADIX * hashval; // p(x) = s_i + x(q(x))
    return hashval;
}


long long encode2 ( const int RADIX, const string & s)
{
    int sum = s[0];
    int product=1;
    for (int i = 1; i < s.length(); i++)
    {
        product= product*RADIX;
        sum = sum + s[i] * product;     
    }     
    return sum;
}


int main()
{
    string test = "aab";
    int char_size=10;
    cout<<encode1(char_size, test)<<" "<<encode2(char_size, test)<<endl;
    return 0;
}