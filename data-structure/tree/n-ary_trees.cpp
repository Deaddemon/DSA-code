//resources: 
//   https://www.geeksforgeeks.org/generic-treesn-array-trees/





//better approach:
//use of vector(dynamic arrays) ,  cant use linked list(expensive access) and arrays(fixed number of addresses)
class node{
  int data;
  vector<node*> children;
  
}

//efficient approach
//remove the link from parent to all children except the first child
// now it can be treated as a binary tree
//with left as firstchild and right as next sibling
class node{
  int data;
  node* firstchild;
  node* secondchild;
}


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};








//related questions
// 1:   https://leetcode.com/problems/n-ary-tree-level-order-traversal/
// sol: https://leetcode.com/submissions/detail/792155789/

