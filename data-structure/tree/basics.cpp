 

-------------------------------------------------------------------------------------------

 
 **Resources**
 
https://www.youtube.com/watch?v=_ANrF3FJm7I&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=2
 
 

----------------------------------------------------------------------------
 
// types of binary tree:
 ======================
// 
// =full binary tree
// either has 0 or 1 children
// 
// =complete binary tree
// all levels completely filled except last level
// last must be filled from left to right
// 
// =perfect BT
// all leaf nodes are at same level
// 
// =balanced BT 
// height of true at max log(n)
// 
// =degenerate tree
// skew trees
// 
----------------------------------------------------------------------------

 // binary tree representaion c++:
 ===============================
 
 struct Node{
 	int data;
 	struct Node* left;
 	struct Node* right;
 	
 	Node(int val){
 		data = val;
 		left = right = NULL;
 	}
 }
 
 
 //calling in main function :
 ================================
 
 main(){
 	struct Node* root = new Node(1);
 	root -> left = new Node(2);
 	root -> right = new Node(3);
 	root -> left -> right = new Node(5);
 	
 	   
 }
 
          1
 	    /   \
 	   2     3
 	   \
 	    5
 	
 
 
----------------------------------------------------------------------------

// traversal techniques:
 ======================
// 
// =preorder
// (root - left - right)
// 
// =inorder
// (left - root - right)
// 
// =postorder
// (left - right - root)
// 
----------------------------------------------------------------------------
 
//codes for = preorder traversal technique:
====================================

//iterative
void preOrder(Node *root) {
        stack<Node *> st;
        
        while(1){
            while(root){
                int a =root->data;
                cout<<a<<" ";
                st.push(root);
                root =  root -> left;
            }
            
            if(st.empty() == true){
                break;
            }
            
{	        root = st.top();
	        st.pop();
	        root =  root -> right;                
            
        }
    }
        
//recursive
void preOrder(Node *root) {
        if(root){
            cout<<root -> data<<" ";
            preOrder(root -> left);
            preOrder(root -> right);
        }
    }

----------------------------------------------------------------------------
 
// codes for = inorder traversal technique:
====================================

//iterative
void inOrder(Node *root) {
        
        stack<Node*> st;
        while(1){
            while(root){
                st.push(root);
                root = root -> left;
            }
            if(st.empty()) break;
            
            root = st.top();
            st.pop();
            
            cout<<root->data<<" ";
            
            root =  root -> right;
        }
         

    }
        
        
//recursive
void inOrder(Node *root) {
         
        if(root){
            inOrder(root -> left);
            cout<<root->data<<" ";
            inOrder(root -> right);
        }

    }


----------------------------------------------------------------------------
 
 //codes for = postorder traversal technique:
====================================

// remember: 
// it is (left - right - root)
// so to access the root 
// either we should know abt left or right
// right pointer will be a good choice 
// bcz it appears near to root 

//iterative
void postOrder(Node *root) {
         
        stack<Node*> st;
        Node *prev = NULL;
        
        do{
            while(root){
                st.push(root);
                root = root -> left;
            }
            
            while(root == NULL && !st.empty()){
                root = st.top();
                if(root -> right == NULL ||
                   root ->right == prev){
                       st.pop();
                       cout<<root -> data<<" ";
                       prev = root ;
                       root = NULL;
                   }
                else{
                    root = root -> right;
                }
            }
        }while(!st.empty());
       
    }
    
        
//recursive
void postOrder(Node *root) {
          
        if(root){
            postOrder(root -> left);
            postOrder(root -> right);
            cout<<root -> data<<" ";
        }

    }


---------------------------------------------------------------------------- 
//coding all preorder,inorder,postorder all at one go using single stack
==========================================================================

void treeTraversals(Node *root){
	vector<int> preOrder , inOrder , postOrder;
	stack<pair<Node*,int>> st;
	st.push({root ,1});
	
	 
	
	while(!st.empty()){
		auto it = st.top() ;
		st.pop();
		
		if(it.second == 1){
			preOrder.push_back(root -> data);
			it.second++;
			 
			st.push(it);
			if(it.first -> left){
				st.push({it.first -> left , 1});
			}
		}
		else if(it.second == 2){
			inOrder.push_back(root -> data);
			it.second++;
			 
			st.push(it);
			if(it.first -> right){
				st.push({it.first -> right , 1});
			}
		}
		else{
			postOrder.push_back(it.first -> data);
		}
	}
}
----------------------------------------------------------------------------

----------------------------------------------------------------------------

----------------------------------------------------------------------------

----------------------------------------------------------------------------

----------------------------------------------------------------------------
