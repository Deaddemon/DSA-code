 https://leetcode.com/problems/balanced-binary-tree/<br>
 //two ways<br>
 //1: O(n*n) : start from root , find hieght of each node using a height function and then check for condn<br>
 //2: O(n)   : calculating height in the same recursion 
 
 https://leetcode.com/problems/diameter-of-binary-tree/<br>
 //three ways<br>
 //1: O(n*n) : calling height as well as diameter function recursively<br>
 //2: O(n)   : finding height within the diameter function recursive call, no need of calling height function<br>
 //3: O(n)   : adjusting the height function to get the diameter<br>
 
 
 https://leetcode.com/problems/binary-tree-maximum-path-sum/<br>
 //there might be various approaches/codes out there try to stick to one<br>
 
 
https://www.codingninjas.com/codestudio/problems/boundary-traversal_790725?utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos <br>
https://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/ <br>
//try to write down the flow first, its easy then : O(N)
//right now i am doing only the anticlockwise

 

https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/ <br>
https://leetcode.com/problems/binary-tree-right-side-view/<br>
https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article<br>
// these all are realted to line concept of vertical order traversal



https://leetcode.com/problems/binary-tree-right-side-view/description/<br>
//two approaches:
//1. level order , worst case at perfect BT
//2. root-right-left order , recursive , worst case at skew tree, but they are very less


https://leetcode.com/problems/symmetric-tree/<br>
 //it is again based on root-right-left order approach
 
 
  
 
 https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/<br>
 //basis of lots of prblm<br>
 //two approaches<br>
 // 1. using root to node path (costly in terms of space)<br>
 // 2. a method in which we return back null if curr!= node we are finding else we return the node<br>
 
 https://leetcode.com/problems/maximum-width-of-binary-tree/<br>
 //level order without using vectors  <br>
 //indexing the nodes <br>
 //not as 1 to n <br>
 //from each level indexing must start from 0 to prevent runtime error
                
 
 
 https://practice.geeksforgeeks.org/problems/children-sum-parent/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article<br>
 
 
 https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/<br>
https://www.codingninjas.com/codestudio/problems/time-to-burn-tree_630563?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos<br>
 parent pointer concept + dfs <br>
 TreeNode/ value might be given<br>
 maintain map of node and parent<br>
 visited map of node and bool value<br>
 and a queue<br>
 when dis++ == k the elemenets in queue are ans<br>
 
 
 https://leetcode.com/problems/count-complete-tree-nodes/<br>
 use the concept of nodes = 1<<h-1 in perfect binary tree<br>
 solve in logn<br>
  
 
 https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/<br>
 https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/<br>
 https://www.youtube.com/watch?v=9GMECGQgWrQ&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=34<br>
 they are similar <br>
 draw and u will know<br>
 
 https://leetcode.com/problems/serialize-and-deserialize-binary-tree/<br>
 concept of stringstream , getline , using them together<br>
 handling string with commas(,) in between<br>
 
 
  https://leetcode.com/problems/search-in-a-binary-search-tree/<br>
 
 https://leetcode.com/problems/insert-into-a-binary-search-tree/<br>
 
 https://leetcode.com/problems/delete-node-in-a-bst/<br>
 two ways: <br>
 1. connecting lefts (lastRight) to rightChild <br>
 2. connecting leftChild to rights(lastLeft)<br>
 figure it out<br>
 
 https://leetcode.com/problems/kth-smallest-element-in-a-bst/<br>
 think of inorder<br>
 
 https://leetcode.com/problems/validate-binary-search-tree/<br>
 LONG_MAX , LONG_MIN also exist<br>
 set a range for every node<br>
 
 https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/<br>
 make use of bst: l < r < R<br>
 node at which splitting happens<br>
 
 https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/<br>
  store upperbound for all node<br>
  for left: ub is parent<br>
  for right: ub is ub of parent node<br>
  
  https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
  three approaches:<br>
  1. O(N) + O(N) || O(N) + O(NlogN)<br>
  2. O(N)<br>
  3. O(H)<br>
  
  https://leetcode.com/problems/binary-search-tree-iterator/<br>
  https://leetcode.com/problems/two-sum-iv-input-is-a-bst/<br>
  iterator vla concept<br>
 
