//twice counter
class Solution
{
    public:
        int countWords(string list[], int n)
        {
           //code here.
           map<string, int> mp;
           for(int i=0; i<n; i++){
               mp[list[i]]++;
           }
           
           int count=0;
           for(auto it:mp){
               if(it.second==2){
                   count++;
               }
           }
           return count;
        }

};