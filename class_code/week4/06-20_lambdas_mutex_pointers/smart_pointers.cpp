#include <iostream>
#include<memory>
#include<array>

using namespace std;


///////////////////////////////////////////////////////////////////////////////
class Temp
{
    public:
        int temp1;
        int temp2;
        string temp3;
        Temp():temp1(1), temp2(2), temp3("three"){}
        void print()
        {
            cout<<temp1<<" "<<temp2<<" "<<temp3<<endl;
        }
};


//Unique pointer are pointers that allocate memory onto the heap and can only
//point to one object. Multiple unqiue pointer are not allowed to point to the
//same object.
///////////////////////////////////////////////////////////////////////////////
void test_unique_ptrs()
{
    array<string,2> test_arr;
    test_arr[0]= "test1";
    test_arr[1]= "test2";

    //test_arr_ptr creates a copy on the heap
    unique_ptr<array<string,2>> test_arr_ptr = make_unique<array<string,2>>(test_arr);
    
    // move works
    unique_ptr<array<string,2>> test_arr_ptr2;
    test_arr_ptr2=move(test_arr_ptr);
    // cout<<test_arr_ptr->at(0)<<" "<<test_arr_ptr->at(1)<<endl; // seg fault
    cout<<test_arr_ptr2->at(0)<<" "<<test_arr_ptr2->at(1)<<endl;
    test_arr_ptr=move(test_arr_ptr2);
    test_arr_ptr2=make_unique<array<string,2>>(array<string,2>({"t1","t2"}));
    cout<<test_arr_ptr2->at(0)<<" "<<test_arr_ptr2->at(1)<<endl;


    //cant do cause copy constructor not allowed
    //unique_ptr<array<string,2>> test_arr_ptr = &test_arr;
    //unique_ptr<array<string,2>> test_arr_ptr2 = test_arr_ptr;

    array<string,2> *p = new array<string,2>();
    p[0][0]="does it work ?";
 
    //unique pointers doesnt give you access via square brackets
    //test_arr_ptr[0][0]="test3";   
    (*test_arr_ptr)[0]="test3";
    cout<<(*test_arr_ptr)[0]<<" not same as: "<<test_arr[0]<<endl;

    //use at function to avoid confusion with dereferencing unique pointers 
    cout<<test_arr_ptr->at(0)<<" "<<test_arr_ptr->at(1)<<endl;


    //syntax for creating arrays of objects on heap 
    //like in project 1: array<Object,2> sequence_= new array<Object,2>[size_];
    unique_ptr<array<int, 3>[]> arr2 = make_unique<array<int,3>[]>(3);
    unique_ptr<array<int, 3>[]> arr3(new array<int, 3>[3]);
    arr2[0]={1,11,111};
    arr2[1]={1,2,3};
    arr2[2]={7,7,7};

    arr3[0]={-1,-2,-3};
    arr3[1]={-1,-1,-1};
    arr3[2]={2,2,2};

    for (int i = 0; i < 3; i++)
    {
        cout<<"Point "<<i<<": ("<<arr2[i][0]<<", "<<arr2[i][1]<<", "
            <<arr2[i][2]<<") \n";

        cout<<"Point "<<i<<": ("<<arr3[i][0]<<", "<<arr3[i][1]<<", "
            <<arr3[i][2]<<") \n";

        cout<<endl;
    }   
}


//Shared pointer are pointers that allocate memory onto the heap 
//Multiple shared pointers can point to the same object. Destructor is invoked
//when object has no shared pointers(uses algorithm reference counting). 
///////////////////////////////////////////////////////////////////////////////
void test_shared_ptrs()
{
    unique_ptr<Temp> obj1 = make_unique<Temp>();

    //shared_ptr<Temp> obj2 = obj1; //not allowed
    shared_ptr<Temp> obj2 = make_shared<Temp>(*obj1);
    //do these point at the same ?
    obj1->temp1=74;
    obj1->print();
    obj2->print();
    cout<<endl;

    // copy constructor works!
    shared_ptr<Temp> obj3 = obj2;
    //do these point at the same ?
    obj2->temp1=88;
    obj2->print();
    obj3->print();
    cout<<endl;
}


///////////////////////////////////////////////////////////////////////////////
int main()
{
    test_shared_ptrs();
    //test_unique_ptrs();    
    return 0;   
}