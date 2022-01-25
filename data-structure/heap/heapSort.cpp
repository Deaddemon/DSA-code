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
    void minHeapify_down(int x);
    void buildHeap();
    void heapSort();
   
    
     
    
 
};
void minHeap:: buildHeap(){
    for(int i= (size-2)/2 ; i>=0; i--){
        minHeapify_down(i);
    }
}
void minHeap:: heapSort(){
    buildHeap();
    for(int i= size-1 ; i>=0 ; i--){
        swap(arr[0] , arr[i]);
        minHeapify_down(0);
    }
}
void minHeap::minHeapify_down(int x){
    int lt = left(x);
    int rt = right(x);
    int smallest= x;
    if(lt<size && arr[lt]<arr[x]) smallest = lt;
    if(rt<size && arr[rt]<arr[smallest]) smallest=rt;
    if(smallest != x){
        swap( arr[x] , arr[smallest]);
        minHeapify_down(smallest);
    }
    
    
    
}
void minHeap::insert(int x){
     
    size++;
    arr[size-1]=x;
    
    int i=size-1;
    while(i!=0 && arr[i]<arr[parent(i)]){
        swap(arr[i],arr[parent(i)]);
        i= parent(i);
    }
    
}
int main() {
    
      
    minHeap h  ;
    
    
    int arr[4]  = {10,50,20,4};
    
    for(int i=0 ; i< 4; i++){
        h.insert(arr[i]);
    }
   
     h.print();
     
}
