// ques: 
// https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
// https://leetcode.com/problems/permutation-in-string/description/


 
    vector<int> findAnagrams(string s, string p) {

        map<char ,int> mp;
        vector<int> res;
        for(auto it: p) mp[it]++;

        int i=0 , j =0 , cnt= mp.size() ;
        int k = p.size();
        while(j < s.size()){
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0) cnt--;
            }

            if(j-i+1 < k){
                j++;
            }else if(j-i+1 == k){

                if(cnt ==0) {
                    res.push_back(i);
                     
                }

                if(mp.find(s[i]) != mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]] == 1) cnt++;
                }

                i++;
                j++;
            }
        }

        return res;
        
    }
 
