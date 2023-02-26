#basic implementation
-trie basic structure
-insert 
-search
-startsWith (prefix)

```c++
 #include <bits/stdc++.h>
using namespace std;
#define  FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int long long

//trie basic structure
//insert 
//search
//startsWith (prefix)
 
struct TrieNode{
	//array contains reference pointers
	TrieNode *array[26];
	bool isLeaf = false;
};

class Node{
	public:
	Trie *root;
	Node(){
		root = new Trie();
		
	}
	
	void insert(string s){
		//make a copy of root trie 
		Trie *node = root;
		for(int i=0 ; i<s.size() ; i++){
			if(! node->array[ s[i]-'a' ] ){
				//putting a reference of character in trie
				 node->array[ s[i]-'a' ] = new Trie();
				 
			}
			//go to that reference
			node = node -> array[s[i] - 'a'];
		}
		//once we traverse the string that means
		//s is inserted so mark the last refernce's isLeaf as true
		node -> isLeaf = true;
	}
	
	//searching for a string in trie
	bool search(string s){
		Trie *node = root;
		for(int i=0 ; i<s.size() ; i++){
			if(! node -> array[s[i]-'a']){
				return false;
			}
			//move to next reference
			node = node -> array[s[i] -'a'];
			
		}
		
		//return the isLeaf of last reference
		//from root to leaf ,then only it is a word
		return node -> isLeaf;
	
	}
	
	//searching for prefix
	bool startsWith(string s){
		Trie* node = root;
		for(int i=0 ; i<s.size() ; i++){
			if( ! node -> array[s[i] -'a']){
				return false;
			}
			node =  node -> array[s[i]- 'a'];
			
		}
		
		//if we come out of loop 
		//that means we have encountered every element of prefix 
		//which guarantees that prefix is present in Trie structure
		return true;
	}
};
 
signed main(){
	FastIO
 
 string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);
    
    
    Node *root = new Node();
 
    // Construct trie
    for (int i = 0; i < n; i++)
    {
    	root->insert( keys[i]);
    }
      
 	 cout<<" searching for word "<<endl;
 	 
    // Search for different keys
    char output[][26] = {"Not present in trie", "Present in trie"};
 
    // Search for different keys
    cout<<"the"<<" --- "<<output[root->search("the")]<<endl;
    cout<<"these"<<" --- "<<output[root->search("these")]<<endl;
    cout<<"their"<<" --- "<<output[root->search( "their")]<<endl;
    cout<<"thaw"<<" --- "<<output[root->search( "thaw")]<<endl;
    
    cout<<" searching for Prefix "<<endl;
    
    // Search for different Prefix
	char prefix[][26] = {"Not present in trie", "Present in trie"};
	
	cout<<"th"<<" --- "<<prefix[root->startsWith("th")]<<endl;
	cout<<"bi"<<" --- "<<prefix[root->startsWith("bi")]<<endl;
	cout<<"an"<<" --- "<<prefix[root->startsWith("an")]<<endl;
	cout<<"ab"<<" --- "<<prefix[root->startsWith("ab")]<<endl;
    
    
 	 	 
  
 
  return 0;
	 }
	 
 
 

```
