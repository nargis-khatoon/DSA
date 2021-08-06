class Solution{
  public:
  int cutRod(int price[], int n)
    {   
        int size=n;
        int length[n];
        for(int i=0;i<n;i++) length[i] = i+1;
        int dp[n+1][size+1];
        
        for(int i=0;i<=n;i++) dp[i][0] = 0;
        for(int i=0;i<=size;i++) dp[0][i] = 0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=size;j++)
            {
                if(length[i-1]<=j)
                dp[i][j] = max(price[i-1] + dp[i][j-length[i-1]], dp[i-1][j]);
                else if(length[i-1]>j)
                dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][size];
        
    }
};
