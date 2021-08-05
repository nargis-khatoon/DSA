//Count all possible paths from top left to bottom right of a mXn matrix
//dp problem easy
//dont forget modulo
class Solution {
  public:
    long long int numberOfPaths(int m, int n){
        // code here
        long long dp[m][n];
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 || j==0)
                dp[i][j]=1;
                else{
                    dp[i][j]=(dp[i-1][j]+dp[i][j-1])%(int)(pow(10,9)+7);
                }
            }
        }
        return dp[m-1][n-1];
    }
};