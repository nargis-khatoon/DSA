//LIMITED COINS
class Solution
{
  public:
  
    long long int count( int S[], int n, int m ) //n=size of S array. m=change for
    {
       
        //code here.
        //INFINITE-unbounded knapsack
        long long int dp[n+1][m+1];
        for(int i=0; i<n+1; i++){
            for(int j=0; j<m+1; j++){
                if(i==0) dp[i][j]=0;
                if(j==0) dp[i][j]=1;
            }
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(S[i-1]<=j){
                    dp[i][j]=dp[i][j-S[i-1]] + dp[i-1][j];
                }
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][m];
    }
};