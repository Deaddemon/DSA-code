-counting word
-counting prefix
-erasing a node

```c++
#include <bits/stdc++.h>
using namespace std;
#define  FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int long long

//counting word
//counting prefix
//erasing a node

struct Trie{
	
	//array contains reference pointers
	Trie *array[26];
	//its basically the count of words
	int cntEndWith =0;
	int cntPrefix = 0;
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
			//increasing the count of prefix
			node -> cntPrefix++;
		}
	
		//increasing the count of word
		node -> cntEndWith++;
	}
	
	//counting words
	int countWordsEqualTo(string s){
		Trie *node = root;
		for(int i=0 ; i<s.size() ; i++){
			if(!node->array[ s[i]-'a' ]){
				return 0;
			}
			node = node -> array[s[i]-'a'];
			
		}
		return node->cntEndWith;
	}
	
	//counting prefix
	int countWordsStartWith(string s){
		Trie *node = root;
		for(int i=0 ; i<s.size() ; i++){
			if(! node -> array[s[i]-'a']){
				return 0;
			}
			node = node -> array[s[i] -'a'];
			
		}
		return node->cntPrefix;
	}	
	
	//deleting some string from trie
	void erase(string s){
		Trie *node = root;
		for(int i=0 ; i<s.size() ; i++){
			if( node -> array[s[i]-'a']){
				node = node ->array[s[i]-'a'];
				node -> cntPrefix--;
			}
		}
		node -> cntEndWith--;
	}
	
	
	 
};
 
signed main(){
	FastIO
 
 string keys[] = {"the", "a",  "the" , "there",
                    "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);
    
    
    Node *root = new Node();
 
    // Construct trie
    for (int i = 0; i < n; i++)
    {
    	root->insert( keys[i]);
    }
      
 
    cout<<"count Word "<<endl;
    cout<<"the"<<" --- "<<root -> countWordsEqualTo("the")<<endl;
    
    cout<<"count Prefix"<<endl;
    cout<<"th"<<" --- "<<root -> countWordsStartWith("th")<<endl;
    
    //it will erase only 1 occurrence
    cout<<"erase one occurrence"<<endl;
    root -> erase("the");
    
    cout<<"count Word "<<endl;
    cout<<"the"<<" --- "<<root -> countWordsEqualTo("the")<<endl;
    
    cout<<"count Prefix"<<endl;
    cout<<"th"<<" --- "<<root -> countWordsStartWith("th")<<endl;
    
 
    
    
 	 	 
  
 
  return 0;
	 }
	 
 
 

```
