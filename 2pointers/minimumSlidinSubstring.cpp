class Solution {
public:
    string minWindow(string s, string t) {
        string ans="";
        int i=0, j=0, right_index=INT_MAX;
        int start=0;
        map<char, int> mp;
        
        for(auto it: t) mp[it]++;
        
        int count=mp.size();
        
        if(mp.find(s[j])!=mp.end()){
            mp[s[j]]--;
            if(mp[s[j]]==0) count--;
        }
        
        while(j<s.length()){
            if(count>0){
                j++;
                    if(mp.find(s[j])!=mp.end()){
                    mp[s[j]]--;
                    if(mp[s[j]]==0) count--;
                }
            
            }
            else if(count==0){
                //potential substring
                if(right_index>j-i+1)
                {
                    right_index=j-i+1;
                    start=i;
                }
                
                while(count==0){
                    if(mp.find(s[i])!=mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]]==1){
                            count++;
                            if(right_index>j-i+1){
                            right_index=j-i+1;
                            start=i;
                            }
                        }
                        i++;
                    }
                    else i++;
                }
            }
        }
        if(right_index!=INT_MAX) 
            return ans.append(s.substr(start, right_index));
            return ans;
    }
};