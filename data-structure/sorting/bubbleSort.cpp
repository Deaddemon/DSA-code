 
 **Resources**
 
 https://www.youtube.com/watch?v=p__ETf2CKY4
 https://www.youtube.com/watch?v=Jdtq5uKz-w4
 

----------------------------------------------------------------------------
 
// bubble sort observations:

// ligheter elements starts to go up or we can say come forward
// the array starts getting sorted from n-1 th element
//  
// for kth pass we get k largest elements
// 
// with each pass highest element in unsorted array
// bubbles up to the highest index of unsorted array
// 

//n-1 passes


//Good to use when memory space is limited.

----------------------------------------------------------------------------

 
 void bubbleSort(vector<int>& v , int n){
 	
 	int flag;
 	for(int i=0 ;i <n-1 ; i++){  //this loop is for repeating the passes
 	
 	flag =0;
 		for(int j=0 ; j<n-1-i ; j++){  //this is for performing the passes
 		     
 			if(v[j] > v[j+1]){
 				swap(v[j] , v[j+1]);
 				flag = 1;
 			}
 		}
 	if(flag == 0){
 		cout<<"swapping was not done means the vector is sorted"
 		break;
 	}
 	}
 }
 
 
 
 TC: O(n^2)
 SC: O(1)
 
 
----------------------------------------------------------------------------

// stable : maintain the order like if two 8s in vector then there order is maintained
// adaptive :we made it adaptive using flag : hence we say bubble can be made as adaptive algorithm 


----------------------------------------------------------------------------
 


----------------------------------------------------------------------------
 



----------------------------------------------------------------------------




---------------------------------------------------------------------------- 
