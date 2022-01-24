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
    void minHeapify_up(int x);
    void decreaseKey(int i,int x);
   
    
     
    
 
};
void minHeap:: decreaseKey(int i ,int x){
    arr[i]=x;
    while(i!=0 && arr[parent(i)]>arr[i]){
        swap(arr[i],arr[parent(i)]);
        i= parent(i);
    }
  //or replace the while loop 
  //minHeapify_up(i);
}
 
 
void minHeap::minHeapify_up(int x){
    
    if(arr[parent(x)]>arr[x]){
        swap(arr[parent(x)] , arr[x]);
        minHeapify_up(parent(x));
    }
    
}
void minHeap::insert(int x){
     
    size++;
    arr[size-1]=x;
      
    minHeapify_up(size-1);
}
int main() {
    
      
    minHeap h  ;
    
    
    int arr[4]  = {150,50,20,4};
    
    for(int i=0 ; i< 4; i++){
        h.insert(arr[i]);
    }
    
    h.decreaseKey(3,10);
   
     h.print();
     
}
