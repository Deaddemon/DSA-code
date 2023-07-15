 
 **Resources**
 
 https://www.youtube.com/watch?v=p__ETf2CKY4
 https://www.youtube.com/watch?v=Jdtq5uKz-w4
 

----------------------------------------------------------------------------


  //divide and conquer algorithm 
  // an element is in sorted position if left elements are smaller and right elements are larger


  //partitioning is the key process of quicksort
  // it involves keeping pth element at its correct position

  //recursively calling takes place after finding quicksort

----------------------------------------------------------------------------

 
int partition(int arr[], int low, int high)
{
    // Choosing the pivot
    int pivot = arr[high];
 
    // Index of smaller element and indicates
    // the right position of pivot found so far
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++) {
 
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
 
            // Increment index of smaller element
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}



void quickSort(int arr[], int low, int high)
{
    if (low < high) {
 
        // pi is partitioning index, arr[p]
        // is now at right place
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

Best Case: \omega (N * log N)   
Average Case: \Theta (N * logN)   
Worst Case: O(N2)
 TC: O(n^2)
 SC: O(1)
 
 
----------------------------------------------------------------------------

 //It is not a stable sort,
//In quick sort, worst case occurs when the pivot element is either greatest or smallest element.

----------------------------------------------------------------------------
 


----------------------------------------------------------------------------
 



----------------------------------------------------------------------------




---------------------------------------------------------------------------- 
