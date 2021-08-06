//Longest Common Substring
//Given two strings. The task is to find the length of the longest common substring
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        int dp[n+1][m+1];
        for(int i=0; i<n+1; i++){
            for(int j=0; j<m+1; j++){
                if(i==0 || j==0) dp[i][j]=0;
            }
        }
        
        int length=0;
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(S1[i-1]==S2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    length=max(length, dp[i][j]);   
                }
                else
                dp[i][j]=0;
            }
        }
        return length;
    }
};