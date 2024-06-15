#include<iostream>
#include"message.h"

using namespace std;

int main()
{
    cout<<"Here is main"<<endl;
    Message m;
    m.setMessage("sent to message class");
    cout<<m.getMessage()<<endl;
    return 0;
}