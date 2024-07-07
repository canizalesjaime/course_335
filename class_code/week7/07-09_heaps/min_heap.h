#pragma once

#include <iostream>
#include <stdexcept>

template <class Comparable>
class MinHeap
{
public:
    ///////////////////////////////////////////////////////////////////////////////
    MinHeap(): current_size_(0),max_size_(100000){}


    ///////////////////////////////////////////////////////////////////////////////
    MinHeap(const Comparable arr[], int size): current_size_(size),max_size_(100000)
    {
        if(size > max_size_) 
            throw std::overflow_error("Overflow, when making heap");

        for (int i=1; i <= current_size_; i++)
            array_[i] = arr[i-1];
            
        heapify();
    }


    ///////////////////////////////////////////////////////////////////////////
    void insert(const Comparable& new_item)
    {
         if (current_size_ >= max_size_) 
            throw std::overflow_error("Overflow, when inserting");

        // Percolate up
        int hole = ++current_size_;
        while (hole > 1 && new_item < array_[hole /2])
        {
            array_[hole] = array_[hole/2];
            hole = hole /2;
        }

        array_[hole] = new_item;
    }


    ///////////////////////////////////////////////////////////////////////////
    void percolateDown(int hole)
    {
        int child ;
        Comparable temp = array_[hole]; // copy the element for later insertion
        while (2* hole <= current_size_) 
        {
            child = hole * 2; // left child of hole
            if (child != current_size_ && array_[child + 1] < array_[child])
            // right child exists and is smaller than left , so make child its index
            child ++;
            if(array_[child] < temp)
            // copy smaller child into hole
            array_[hole] = array_[child];
            else break; // both children are bigger than hole
            // repeat with hold being child that was copied up
            hole = child;
        }
        array_[hole] = temp;
    }


    ///////////////////////////////////////////////////////////////////////////
    Comparable deleteMin()
    {
        if (current_size_ <= 0) 
            throw std::underflow_error("Underflow, when making heap");
        
        Comparable popped=array_[1];
        array_[1] = array_[current_size_];
        current_size_--;
        percolateDown(1);
        return popped;
    }


    ///////////////////////////////////////////////////////////////////////////
    void heapify()
    {
        for ( int i = current_size_/2; i > 0; i--)
            percolateDown(i);
    }


    ///////////////////////////////////////////////////////////////////////////
    int getSize()
    {
        return current_size_;
    }


    ///////////////////////////////////////////////////////////////////////////
    void print()
    {
        for(int i = 1; i <= current_size_; i++)
           std::cout<<array_[i]<<" ";
        
        std::cout<<std::endl;
    }


private:
    Comparable array_[100000];
    int current_size_;
    int max_size_;
};
