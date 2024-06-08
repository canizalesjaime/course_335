#include<iostream>
#include<iterator>
#include<algorithm>

class Ticker 
{
    private :
        int & count ;
    public :
        Ticker ( int & n ) : count ( n ) {}
        int operator () ()
        {
            return count ++;
        }
};


int main ()
{
    int numbers [20];
    int startvalue (10) ;
    std :: generate_n ( numbers , 20 , Ticker ( startvalue ) ) ;
    std :: cout << " Numbers given out today are : " ;
    for ( int i =0; i <20; ++ i )
        std :: cout << ' ' << numbers [ i ];
    std :: cout << std::endl;

    return 0;
}

