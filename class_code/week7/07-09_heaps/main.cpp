#include "min_heap.h"
#include<iostream>

using namespace std;

template <class Comparable>
void deleteAll(MinHeap<Comparable>& heap)
{
    int size = heap.getSize();
    for(int i = 0; i < size; i++)
        cout<<heap.deleteMin()<<" ";
    cout<<endl;
}

int main()
{
    MinHeap<int> heap1;
    heap1.insert(10);
    heap1.insert(-3);
    heap1.insert(17);
    heap1.insert(4);
    heap1.insert(1);
    heap1.insert(100);

    heap1.print();

    double arr[] = {2.718, .618, 1.618, 3.14, -1, 1.414, .707};
    MinHeap<double> heap2(arr, 7);
    heap2.print();

    // test delete
    cout<<"First Delete: ";
    deleteAll(heap1);
    cout<<"Second Delete: ";
    deleteAll(heap1);

    cout<<"First Delete: ";
    deleteAll(heap2);
    cout<<"Second Delete: ";
    deleteAll(heap2);

    return 0;
}