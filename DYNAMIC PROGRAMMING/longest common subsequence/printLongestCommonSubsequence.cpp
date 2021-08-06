//ERROR CODE

    //Function to find the length of longest common subsequence in two strings.
    vector<string> lcs(int x, int y, vector<string> s1, vector<string> s2)
    {
        // your code here
        int dp[x+1][y+1];
        for(int i=0; i<x+1; i++){
            for(int j=0; j<y+1; j++){
                if(i==0 || j==0) dp[i][j]=0;
            }
        }
        for(int i=1; i<x+1; i++){
            for(int j=1; j<y+1; j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        vector<string> ans;
        int i=x;
        int j=y;
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                ans.push_back(s1[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1])
                {
                i--;}
                else{
                    j--;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

// int main(){
    
//     vector<string> a;
//     vector<string>b;
//     cin>>a>>b;
//     cout<<lcs(a.size(), b.size(), a, b);
// }