//find and union
//intitialize array of size n
 // int find(int x){
 	// if(v[x] == x) return x;
 	// return find(v[x]);
 // }
//  
 // void union(int a , int b){
 	// int x = find(a);
 	// int y = find(b);
 	// if(x==y) return ;
 	// p[y] = x;
 // }
// 

//resources 
//https://www.youtube.com/watch?v=ayW5B2W9hfo


//ques
//https://leetcode.com/problems/satisfiability-of-equality-equations/

class Solution {
public:
    int arr[26];
    
    int find(int x){
        if(arr[x] == x) return x;
        else return arr[x] = find(arr[x]);
    }
    bool equationsPossible(vector<string>& e) {
        
        
        for(int i=0 ; i<26 ; i++){
             arr[i] =i;
        }
         for(int i=0 ; i<e.size() ; i++){
             
             if(e[i][1]== '='){
                 arr[ find(e[i][0]-'a')] = arr[ find(e[i][3]-'a')];
             }
        }
         for(int i=0 ; i<e.size() ; i++){
             
             if(e[i][1]== '!' &&
                 arr[ find(e[i][0]-'a')] == arr[ find(e[i][3]-'a')]){
                 return false;
             }
             }
        return true;
        }
    
    
        
    
};
