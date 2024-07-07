#include "DisjSets.h"
#include <iostream>

using namespace std;

DisjSets :: DisjSets ( int numElements ) : s ( numElements )
{
    for ( int i = 0; i < s.size(); i++ )
        s [ i ] = -1;
}
 
void DisjSets::Union( int root1, int root2 ) 
{ 
    if (root1 != root2)
    {
        if ( s[root2] < s[root1] ) 
        {       
            //root2 is deeper
            s[root2] += s[root1]; 
            s[root1] = root2; 
        }
        
        else 
        {
            // root1 is deeper 
            s[root1] += s[root2]; 
            s[root2] = root1;
        }
    }
}

int DisjSets::find( int x ) 
{ 
    if ( s[ x ] < 0 ) 
        return x; 
    
    else return s[ x ] = find( s[ x ] );
}

void DisjSets::print()
{
    cout<<s.size()<<endl;
    for(int i = 0; i< s.size();i++)
        cout<<s[i]<<" ";
}