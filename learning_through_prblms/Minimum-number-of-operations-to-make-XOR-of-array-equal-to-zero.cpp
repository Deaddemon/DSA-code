https://iq.opengenus.org/minimum-operations-xor-zero/

Input:
No. of elements in array = 4
Elements = 5 5 4 4
Output:
0
  
  
 
Optimized solution: This solution is an optimzed veersion of the solution above. In this solution we will utilise three important facts about XOR:
It is associative.
XOR of an element with itself is zero.
XOR of a number with zero is the number itself.
The above behavior implies an important behavior of XOR that is if M = a^b ( a and b are numbers ) then M^b will be equal to a.
Now with this property in hand, we will make the process of finding the XOR of all elements excluding the ith element O(1). First, we will find XOR of all the elements of the array and store it in a variable ( lets say A ). Then to find the XOR of all the elements excluding the ith element we will do XOR(A, array[i]). Thus the cost for the ith element will be absolute(array[i]-XOR(A, array[i])). We will calculate the cost for each element of the array and the minimum of these costs will be the answer.
