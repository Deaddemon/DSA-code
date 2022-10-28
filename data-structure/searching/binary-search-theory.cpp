 // binary search is the algorithm which is
 // applicable to 
 // monotonic functions: whihc maintains a given order
//  
 // example :
 // increasing 
 // decreasing 
 // x square vala function
 // predicate function: functions that return a single TRUE or FALSE


 
//notes:
//while solving question its not only 
// that we consider indexes of the given array
// but we may consider values in range somehow derived from items in array
// Template #1 (left <= right):
// 
// Most basic and elementary form of Binary Search
// Search Condition can be determined without comparing to the element's neighbors (or use specific elements around it)
// No post-processing required because at each step, you are checking to see if the element has been found. If you reach the end, then you know the element is not found
//  
// 
// Template #2 (left < right):
// 
// An advanced way to implement Binary Search.
// Search Condition needs to access the element's immediate right neighbor
// Use the element's right neighbor to determine if the condition is met and decide whether to go left or right
// Guarantees Search Space is at least 2 in size at each step
// Post-processing required. Loop/Recursion ends when you have 1 element left. Need to assess if the remaining element meets the condition.
//  
// 
// Template #3 (left + 1 < right):
// 
// An alternative way to implement Binary Search
// Search Condition needs to access element's immediate left and right neighbors
// Use element's neighbors to determine if the condition is met and decide whether to go left or right
// Guarantees Search Space is at least 3 in size at each step
// Post-processing required. Loop/Recursion ends when you have 2 elements left. Need to assess if the remaining elements meet the condition.
