resources:<br>
https://www.youtube.com/watch?v=sSno9rV8Rhg<br>
https://www.geeksforgeeks.org/tabulation-vs-memoization/<br>
https://jarednielsen.com/dynamic-programming-memoization-tabulation/<br>

question:<br>
https://leetcode.com/problems/longest-common-subsequence/description/<br>
sol:<br>
https://leetcode.com/problems/longest-common-subsequence/description/<br>

it as advanced recursion.<br>
one call in recursion will never need dp.
recursive-> 2 calls , probability is there that it will need dp.<br>
used to solve overlapping problems<br>



identification:<br>
1.choice<br>
2.optimal (maximum,largest,etc) solution asked   <br>

dp: efficiently solving a big problem by breaking it down into smaller problems and reusing the solutions to the smaller problems to avoid solving them more than once<br>

Dynamic Programming: Optimal Substructure and Overlapping Subproblems<br>
There are two criteria for a dynamic programming approach to problem solving:<br>
1.Optimal substructure<br>
2.Overlapping subproblems<br>

What is optimal substructure?<br>
The solution to a larger problem can be found by combining the returned values of its smaller problems. <br>

What are overlapping subproblems?<br>
The solution to a larger problem recognizes redundancy in the smaller problems and caches those solutions for later recall rather than repeatedly solving the same problem, making the algorithm much more efficient.
We solve the same problems repeatedly in our branches.<br>
 

☝️ This might sound a lot like divide and conquer, but divide and conquer algorithms, such as merge sort and quick sort, don’t solve overlapping subproblems. They continually divide a problem into smaller, yet new, problems, then recombine the smaller solutions into a solution to the larger problem.<br>

two approaches:<br>
1.Top-down  <br>
2.Bottom-up <br>

We refer to top-down solutions as memoization and bottom-up as tabulation.<br>





What Problem(s) Does Dynamic Programming Solve?<br>
Dynamic programming helps us optimize solutions to problems by caching values for future use<br>
Dynamic programming helps us improve the runtimes of recursive algorithms<br>

