
### index of  first and last occurrence of a element and its variations
// https://practice.geeksforgeeks.org/problems/find-first-and-last-occurrence-of-x0849/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


### count 1s in a sorted binary array

### find_index_of_given_number_in_infinite_sorted_array
```cpp
int search(int arr[] , int x){
	int low=0;
	int high = 1;
 
	while(arr[high]< x){
		 
		low = high;
		high = high*2;
		
	}
	
	return binarSearch(arr[], low, high, x);
}
```

### return the index of a given number x, in a rotated sorted array
```cpp
int search(int A[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
        
        
        while(l <= h ){
            int mid = l + (h-l)/2;
            
            if(key == A[mid]){
                return mid;
            }else if(A[l] <= A[mid]){
                if( key >= A[l] && key <= A[mid]){
                   
                    h = mid-1;
                }else{
                     
                       l = mid +1;
                }
            }else{
                if( key <= A[h] && key >= A[mid]){
                    l = mid +1;
                }else{
                    h = mid-1;
                }
                
            }


        }
        
        return -1;
        
}

```

### find peak element in array
```cpp
int findMaximum(int arr[], int n) {
	     
	    int l=0 , h = n-1;
	    int ans = 0;
	    while(l<=h){
	        int mid = l+ (h-l)/2;
	        
	        
	        if( (mid == 0 || arr[mid-1]<=arr[mid]) && (arr[mid+1]<=arr[mid] || mid== n-1)){
	           return arr[mid];
	        }
	        else if(arr[mid-1] >= arr[mid]){
	            h = mid-1;
	        }else{
	            l= mid+1;
	        }
	    }
	    
	    return -1;
	    
	}
```

### find 2 elements in array whose sum is X

### find 3 elements in array whose sum is X



