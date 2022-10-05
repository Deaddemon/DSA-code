
// 3+2*2+3
//its  postfix  322*+2+

//https://leetcode.com/problems/basic-calculator-ii/



  int pres(char c){
        if(c == '*' || c=='/') return 1;
        else return 0;
    }
    string prefixToPosfix( string &s){
        
        string ans="";
        stack<char> st;
        for(int i=0 ; i<s.size() ; i++){
            
            if(s[i]== ' ') continue;
            else if(isdigit(s[i])){
                ans += s[i];
            }else{
                ans += '|';
                
                if(st.size()==0){
                    st.push(s[i]);
                    
                }else {
                    while(size(st) && pres(s[i]) <= pres(st.top())){
                    ans += st.top();
                    st.pop();
                    
                }
                    
                    st.push(s[i]);
                
                
            }
            
        }
    }
        ans += '|';
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
    return ans;
    }
