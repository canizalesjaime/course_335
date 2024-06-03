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
        Entity(){}
        Entity(string s, vector<int> x): id_(s), data_(x) {}
        
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

};

int main()
{
    Entity a;
    Entity b("1", vector<int>({1,2}));
    Entity c[3];
    c[0]=a;
    Entity *c_ptr2=new Entity[3];
    unique_ptr<Entity> ptr_c = make_unique<Entity>(3);
    
    std::cout<<ptr[0].<<endl;
    
    //string str1 = "2";
    //vector<int> vec1({3,4});
    //Entity c(str1, vec1);

}