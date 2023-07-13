 
**Sorting Terminology**
 
https://www.geeksforgeeks.org/sorting-terminology/
 
 
**Time complexities**

https://www.geeksforgeeks.org/time-complexities-of-all-sorting-algorithms/


**Resources**

https://www.youtube.com/watch?v=6pV2IF0fgKY&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=33
https://www.youtube.com/watch?v=mB5HXBb_HY8&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=39&t=9s
https://www.youtube.com/watch?v=ak-pz7tS5DE&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=36
https://www.javatpoint.com/merge-sort
https://www.youtube.com/watch?v=cWvruDR-hJA&t=2s




----------------------------------------------------------------------------
this is how u basically merge two sorted arrays
it is called

**2-Way Merging**
(:this is iterative)
alogorithm merge(A,B,m,n){
	i=0 ; j=0 ; k=0;
	
	while(i<m && j<n){
		if(A[i] < B[j]){
			C[k++] = A[i++];
		}else{
			C[k++] = B[j++];
		}
	}
	
	for(; i<m ; ){
		C[k++] = A[i++];
	}
	
	for(; j<n){
		C[k++] = B[j++];
	}
	
}


TC:  nlogn  (base2)
----------------------------------------------------------------------------

**MergeSort**
(:recursive)
(: divide and conquer algorithm)
it will recursively divide the given array to smaller size
to single element to be precise 
and then merge them 
way back to top from bottom


void mergeSort(vector<int> &arr , int l , int r){
	
	if(r>l){
		int mid = l + (r-l)/2;
		mergeSort(arr, l , mid);
		mergeSort(arr, mid+1 , r);
		
		merge(arr, l, mid , r);
	}
}




----------------------------------------------------------------------------

proper implementation:

void merge(int a[] , int l , int m , int h){
	
	int n1 = m+1 - l;
	int n2 = e - m;
	
	int left[] = new int[n1];  //or int left[n1] ;
	int right[] = new int[n2]; // or int right[n2];
	
	
	//copying the data first half to left array
	for(int i=0; i<n1; i++){
		left[i] = a[b+i];
	}
	//copying the data of second half to right array
	for(int i=0 ; i<n2 ; i++){
		right[i] = a[m+1+i];
	}
	
	int i=0 , j=0,k= l;
	while(i<n1 && j<n2){
		if(left[i] < right[j]){
			a[k++] = left[i++];
			 
		}else{
			a[k++] = right[j++];
			 
		}
	}
	
	for(;i<n1;){
		a[k++] = left[i++];
	}
	
	for(;j<n2;){
		a[k++] = right[j++];
	}
	
}

void mergeSort(int a[] , int l , int h){
	if(h>l){
		int mid = l+(h-l)/2;
		mergeSort(a , l , mid);
		mergeSort(a , mid+1 , h);
		merge(a, l , mid, h);
	}
}


for merging TC: O(n)



----------------------------------------------------------------------------
pros:

suitable for large size list
linked list
support external sorting
Stable (order of duplicate is maintained , previous arrangement is not disturbed)




----------------------------------------------------------------------------
cons:

extra space (not inplace sorting )
no small problem
for smaller input:merge sort(nlogn) is slower than insertion sort(n^2)
recursive 




----------------------------------------------------------------------------
You will use it indirectly most of the times



---------------------------------------------------------------------------- 
