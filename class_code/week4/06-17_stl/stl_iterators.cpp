/*For more details on what was covered on 06.14.2023, you can visit: 
https://cplusplus.com/reference/stl/ and review information on vectors, list,
and unordered_maps. In particular, review iterators for each template class,
insert and erase for each template class, and the find function for unordered 
maps. We also discussed using the limits library for finding largest and 
smallest value, and using the "?" ternary operator.*/

#include <iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<set>
#include<limits>

using namespace std;

void test_vector()
{
    /*for(int x: vec) // then show with &
    {
        cout<<x<<" ";
        x=7;
    }
    cout<<"printed first time"<<endl;

    for(int x : vec) cout<<x<<" "; 

    cout<<"printed second time"<<endl;

    int max_val = std::numeric_limits<int>::min();
    cout<<"minimum int value: "<<max_val<<endl;
    for(int x : vec) max_val = (x>max_val)?x:max_val; //ternary operator ?

    cout<<"max value in vec "<<max_val<<endl;

    for (auto x: vec) cout<<x<<" ";
    cout<<"printed third time with auto"<<endl;

     //iterators are pointers used in stl for traversing through data structures
     vector<int>::iterator itr;

     for (itr = vec.begin(); itr != vec.end(); itr++)
        cout<<*itr<<" ";
    cout<<"printed 4th time with iterators"<<endl;*/
    vector<int> vec({2,4,6,8,10,47,1,5});
    //use cases for iterators insert 
    vec.insert(vec.begin()+3,399);
    for (auto x: vec) cout<<x<<" ";
    cout<<"printed fifth time with inserted element"<<endl;

    vector<int> sub_vec = {3,2,1};
    vec.insert(vec.begin()+3,sub_vec.begin(),sub_vec.end());
    for (auto x: vec) cout<<x<<" ";
    cout<<"printed sixth time with inserted sub vector"<<endl;

    ///////////////////////////////////////////////////////////////////////////
    //use cases for iterators erase 
    vec.erase(vec.begin()+5);
    for (auto x: vec) cout<<x<<" ";
    cout<<"printed seventh time with erased element"<<endl;
    
    vec.erase(vec.begin()+1,vec.begin()+3);
    for (auto x: vec) cout<<x<<" ";
    cout<<"printed eighth time with erased sequence"<<endl;

    //delete lasty three elements
    vec.erase(vec.end()-3,vec.end());
    for (auto x: vec) cout<<x<<" ";
    cout<<"printed nineth time with erased sequence"<<endl;
    
}

void test_list()
{
    list<double> my_list1({1,2,30,4.2});

    for(auto x : my_list1) cout<<x<<" ";
    cout<<endl;

    //cout<<my_list1[1]<<endl; //not allowed

    int i = 0;
    for(auto x : my_list1)
    {
        if (i == 3) cout<<x;
        i++;
    } 
    cout<<endl;


}

void test_unordered_maps()
{
    unordered_map<int, string> my_map1;
    my_map1[1]="data1";
    my_map1[2]="data2";
    my_map1[3]="data1";
    my_map1[1]="data3"; //rewrites first assignment, all keys unique
    my_map1[4]="data4";

    for(auto x : my_map1)
        cout<<x.first<<" "<<x.second<<";";

    cout<<endl;
    auto search1 = my_map1.find(1);
    
    if(search1 != my_map1.end())
        cout << "Found " << search1->first << " " << search1->second << endl;
    else
        cout<<"Not found"<<endl;

    auto search2 = my_map1.find(7);
    if(search2 != my_map1.end())
        cout << "Found " << search2->first << " " << search2->second << endl;
    else
        cout<<"Not found"<<endl; 

}

int main()
{
   test_list();

   return 0;
}