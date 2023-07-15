 
 **Resources**
 
 // https://iq.opengenus.org/time-and-space-complexity-of-counting-sort/
 // https://www.geeksforgeeks.org/counting-sort/
   
----------------------------------------------------------------------------
 

----------------------------------------------------------------------------


// The main function that sort
// the given string arr[] in
// alphabetical order
void countSort(char arr[])
{
    // The output character array
    // that will have sorted arr
    char output[strlen(arr)];

    // Create a count array to store count
    // of individual characters and
    // initialize count array as 0
    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));

    // Store count of each character
    for (i = 0; arr[i]; ++i)
        ++count[arr[i]];

    // Change count[i] so that count[i]
    // now contains actual position of
    // this character in output array
    for (i = 1; i <= RANGE; ++i)
        count[i] += count[i - 1];

    // Build the output character array
    for (i = 0; arr[i]; ++i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }

    /*
    For Stable algorithm
    for (i = sizeof(arr)-1; i>=0; --i)
    {
        output[count[arr[i]]-1] = arr[i];
        --count[arr[i]];
    }
 
    // Copy the output array to arr,
    // so that arr now contains
    // sorted characters
    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];
}
 
 

 
----------------------------------------------------------------------------

In short,

Time complexity: O(N+K)
Space Complexity: O(K)
  
Worst case: when data is skewed and range is large
Best Case: When all elements are same
Average Case: O(N+K) (N & K equally dominant)
where:

N is the number of elements
K is the range of elements (K = largest element - smallest element)
 
----------------------------------------------------------------------------
 


----------------------------------------------------------------------------
 // stable
// Counting sort is efficient if the range of input data is not significantly greater than the number of objects to be sorted. 


----------------------------------------------------------------------------




---------------------------------------------------------------------------- 
