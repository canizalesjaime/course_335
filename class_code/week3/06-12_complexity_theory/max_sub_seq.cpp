#include<iostream>
#include<vector>
#include<cstdlib>
#include <time.h>

using namespace std;

int MaxSubSeqSumBruteForce(const vector<int> & vec);
int MaxSubSeqSumBruteForceWorst(const vector<int> & vec);
int MaxSubSeqSumLinear(const vector<int>& vec);
int MaxSubSeqSumRec(const vector <int>& vec, int left, int right);
vector<int> RandomVec(int size, int range);

int main()
{
    //vector<int> vec({-2, 11, -4, 13, -5, -2 });
    //vector<int> vec = RandomVec(11,100);
    vector<int> vec({1, 2, -4, 1, 5, -10, 4, 1});
    for(const auto& i : vec)
        cout<<i<<" ";
    cout<<endl;

    //cout<<"max subseq sum: "<<MaxSubSeqSumBruteForce(vec)<<endl;
    cout<<MaxSubSeqSumBruteForce(vec)<<" vs "
        <<MaxSubSeqSumBruteForceWorst(vec)<<" vs "
        <<MaxSubSeqSumLinear(vec)<<" vs "
        <<MaxSubSeqSumRec(vec,0,vec.size()-1)<<endl;

    return 0;        
}

///////////////////////////////////////////////////////////////////////////////
vector<int> RandomVec(int size, int range)
{
    srand(time(0));
    vector<int> vec(size);
    for(auto &i : vec)
    {
        int is_neg = rand() % 2;
        int rand_num=rand() % range;
        if (is_neg == 0) i = rand_num;
        else i = -rand_num;
    }
    return vec;
}

///////////////////////////////////////////////////////////////////////////////
int MaxSubSeqSumBruteForce(const vector<int> & vec) 
{
    int max_sum = 0;
    for(int i = 0; i < vec.size(); i++)
    {
        int curr_sum=0;
        for(int j = i; j < vec.size(); j++)
        {    
            curr_sum += vec[j];
            //if (curr_sum > max_sum) max_sum = curr_sum;
            max_sum=max(curr_sum,max_sum);
        }
    }

    return max_sum;
}

///////////////////////////////////////////////////////////////////////////////
int MaxSubSeqSumBruteForceWorst(const vector<int>& vec)
{
    int max = 0;
    for ( int i = 0; i < vec.size() ; i ++)
        for ( int j = i ; j < vec.size() ; j ++)
         {
            int sum = 0;
            for ( int k = i ; k <= j ; k ++)
                sum += vec[k];
            
            if ( max < sum ) max = sum ;
}
    return max ;
}

///////////////////////////////////////////////////////////////////////////////
int MaxSubSeqSumLinear(const vector<int>& vec)
{
    int max_sum = 0 , this_sum = 0;
    for ( int i = 0; i < vec.size(); i++ )
    {
        this_sum += vec[i];
        if ( this_sum > max_sum ) max_sum = this_sum ;
    
        // this vec[ i ] made the initial sequence negative - start over
        else if ( this_sum < 0 ) this_sum = 0;           
    }
    return max_sum ;
}

///////////////////////////////////////////////////////////////////////////////
/* *
Recursive maximum contiguous subsequence sum algorithm . Finds maximum sum
in subarray spanning a [ left .. right ]. Does not attempt to maintain
actual best sequence .
*/
int MaxSubSeqSumRec(const vector <int>& vec, int left, int right)
{
    if (left == right) // Base cases
        if (vec[left] > 0) return vec[left];
        else return 0;

    int center = (left + right)/2;
    // Recursion here 
    int max_left_sum = MaxSubSeqSumRec(vec, left , center);
    int max_right_sum = MaxSubSeqSumRec(vec, center + 1, right);

    int max_left_border_sum = 0, left_border_sum = 0;
    for (int i = center; i >= left; i--) 
    {
        left_border_sum += vec[i];
        if (left_border_sum > max_left_border_sum)
            max_left_border_sum = left_border_sum;
    }

    int max_right_border_sum = 0, right_border_sum = 0;
    for (int i = center+1; i <= right; i++) 
    {
        right_border_sum += vec[i];
        if (right_border_sum > max_right_border_sum)
            max_right_border_sum = right_border_sum;
    }

    return max(max(max_left_sum, max_right_sum), 
               max_left_border_sum + max_right_border_sum);
}