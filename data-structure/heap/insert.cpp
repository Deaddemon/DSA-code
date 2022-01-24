#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;


const int s= 101;

class minHeap{
     
    public:
    int arr[s];
    int size;
    int capacity;
    
    minHeap(){
        
        size=0;
        capacity=s;
    }
    
    int left(int i) {return (2*i+1);}
    int right(int i){ return (2*i+2);}
    int parent(int i) {return (i-1)/2;}
    
    
    void print(){
        for(int i=0; i<size ; i++){
            cout<<arr[i]<<" ";
        }
    }
     
    void insert( int x); 
   
    
     
    
 
};

void minHeap::insert(int x){
    if(size==capacity) return;
    size++;
    arr[size-1]=x;
     
    for(int i=size-1 ; i!=0 && arr[parent(i)] > arr[i] ; ){
        swap(arr[i] ,  arr[parent(i)]);
        i= parent(i);
 
    }}
int main() {
    
      
    minHeap h  ;
    
    
    int arr[4]  = {7,14,2,3};
    
    for(int i=0 ; i< 4; i++){
        h.insert(arr[i]);
    }
   
     h.print();
     
}
