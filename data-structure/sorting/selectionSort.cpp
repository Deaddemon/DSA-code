 
 **Resources**
 
//https://takeuforward.org/sorting/selection-sort-algorithm/
//https://matcha.fyi/selection-sort-javascript/#:~:text=Selection%20sort%20can%20be%20good,less%20temporary%20storage%20space%20used.

----------------------------------------------------------------------------
 

//selection sort doesn't go around swapping things until the very end, 
----------------------------------------------------------------------------

 
 void selectionSort(vector<int>& v , int n){
 	
 	for(int i=0 ; i<n ; i++){
 		int min_index = i;
 		for(int j = i+1; j<n ; j++){
 			if(v[j] < v[min_index]){
 				min_index = j;
 			}
 		}
 		
 		swap(v[i] , v[min_index]);
 	}
 	

 }
 
 
 TC: O(n^2)
 SC: O(1)
 
 
----------------------------------------------------------------------------

// unstable : doesnt maintain the order like if two 8s in vector then there order is not maintained



----------------------------------------------------------------------------
 


----------------------------------------------------------------------------
 



----------------------------------------------------------------------------




---------------------------------------------------------------------------- 
