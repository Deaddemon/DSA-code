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
