#include <vector>
#include <iostream>
#include<memory>
#include<array>

using namespace std;


class Temp
{
    private:
        int temp1;
        int temp2;
        string temp3;

};

int main()
{
    array<string,2> test_arr;
    test_arr[0]= "yooo";
    test_arr[1]= "yooo2";

    unique_ptr<array<string,2>> arr1 = make_unique<array<string,2>>();
    (*arr1)[0]="Hello1";
    arr1[1]="Hello2";

    for(int i = 0; i < arr1->size(); i++)
        cout<<arr1->at(0)<<endl;


    unique_ptr<array<int, 3>[]> a = make_unique<array<int,3>[]>(3);
    //unique_ptr<array<int, 3>[]> a(new array<int, 3>[3]);
    a[0]={1,11,111};
    a[1]={1,2,3};
    a[2]={7,7,7};

    for (int i = 0; i < 3; i++)
        cout<<"Point "<<i<<": ("<<a[i][0]<<", "<<a[i][1]<<", "<<a[i][2]<<") \n";

    unique_ptr<vector<vector<int>>> b = make_unique<vector<vector<int>>>();
    
    b->push_back({7,7,7});
    b->push_back({8,8});

    shared_ptr<vector<vector<int>>> c = make_shared<vector<vector<int>>>();
    c->push_back({4,4,4});
    c->push_back({3,3});

    shared_ptr<vector<vector<int>>> d = c;

    cout<<b->size()<<" "<<b->at(1).at(0)<<" "<<b->at(0).at(1)<<" "<<endl;
    cout<<c->size()<<" "<<c->at(1).at(0)<<" "<<c->at(0).at(1)<<" "<<endl;
    cout<<d->size()<<" "<<d->at(1).at(0)<<" "<<d->at(0).at(1)<<" "<<endl;

    return 0;   
}