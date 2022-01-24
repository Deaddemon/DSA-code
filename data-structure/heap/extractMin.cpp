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
    int extractMin();
   
     
 
};
int minHeap::extractMin(){
    if(size==0) return -1;
    if(size==1){
        size-=1;
        return arr[0];
    }
    swap(arr[0] , arr[size-1]);
    size-=1;
    minHeapify_down(0);
    return arr[size];
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
      
    minHeapify_up(size-1);
}
int main() {
    
      
    minHeap h  ;
    
    
    int arr[4]  = {150,50,20,4};
    
    for(int i=0 ; i< 4; i++){
        h.insert(arr[i]);
    }
    
    int x =  h.extractMin();
    cout<<x<<endl;
   
     h.print();
     
}
