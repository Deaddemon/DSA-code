 
 **Resources**
 // https://www.youtube.com/watch?v=HqPJF2L5h9U
 

----------------------------------------------------------------------------
 
// heap
   // insert - add as left most element and then by swapping goes to root it is max or min(adjustment), to preserve complete binary tree 
   // delete - root deleted , but at roots place right most element will come to maintain complete binary tree

//steps of heap sort
   // 1. create a heap of given elements
   // 2. delete elements one by one  

// nlogn
   // we insert n elements
   // insertion worst case tc is logn (height of tree)

// heapify : O(n)
// create : O(nlogn)
----------------------------------------------------------------------------

 
// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(int arr[], int N, int i)
{

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int l = 2 * i + 1;

    // right = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest
    // so far
    if (r < N && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int N)
{

    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    // One by one extract an element
    // from heap
    for (int i = N - 1; i > 0; i--) {

        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// best case: O(n(log(n))
// avg case: O(n(log(n))
// worst case : O(n(log(n))

 TC: O(n^2)
 SC: O(1)
 
 
----------------------------------------------------------------------------


// Heap sort is an in-place algorithm. 
// Heap sort is unstable. It might rearrange the relative order.
// Worst Case Complexity - It occurs when the array elements are required to be sorted in reverse order.

   
----------------------------------------------------------------------------
 

 
---------------------------------------------------------------------------- 
