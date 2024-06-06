#include <vector>
#include <string>
#include <iostream>
#include<memory>

using namespace std;

class Entity 
{
    private:
        string id_;
        vector<int> data_;


    public:
        Entity(){} //default constructor
        Entity(string s, vector<int> x): id_(s), data_(x) {} //constructor

        
        Entity(const Entity& other)//copy constuctor
        {
            cout<<"copy constructor called"<<endl;
            id_ = other.id_;
            data_ = other.data_;
        }


        Entity& operator=(const Entity &rhs) //copy assignment operator
        {
            //Entity copy = rhs;
            //swap(*this, copy);
            cout<<"copy assignment called "<<endl;
            id_=rhs.id_;
            data_=rhs.data_;
            return *this;
        }


        Entity(Entity&& other)//move constuctor
        {
           cout<<"move constructor called"<<endl;
           id_ = other.id_;
           data_ = other.data_;
           other.id_ ="";
           other.data_=vector<int>(0);
        }


        Entity& operator=(Entity &&rhs) //move assignment operator
        {
        cout<<"move assignment called"<<endl;
        //std::swap(id_, rhs.id_);
        //std::swap(data_, rhs.data_);
        id_ = rhs.id_;
        data_ = rhs.data_;
        rhs.id_ ="";
        rhs.data_=vector<int>(0);
        return *this;
        }


        ~Entity()
        {
            cout<<"destructor called"<<endl;
            id_ = "";
            data_=vector<int>(0);
        }


        string GetId(){return id_;}


        void PrintInfo()
        {
            if (id_ != "")
            {
                cout<<id_<<endl;
                for(auto i : data_) cout<<i<<" ";
                cout<<endl;
            }

            else {cout<<"nothing to print"<<endl;}
        }
};

int main()
{
    Entity a; // object created using default constructor
    Entity b("1", vector<int>({1,2})); //object created using a constructor
    Entity x("27", vector<int>({27,37}));
    Entity c(std::move(b)); // move constructor called
    Entity d(a); // copy constructor called

    Entity y("333", vector<int>({203,314}));
    b=x; //copy assignment
    a=move(y);//move assignment
    a.PrintInfo();
    //cout<<"HELLOOOOOOO"<<endl;
}