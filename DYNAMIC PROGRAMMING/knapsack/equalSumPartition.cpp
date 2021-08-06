//SAME AS SUBSET SUM PROBLEM
class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
        }
        if(sum&1) return 0;
        int w=sum/2;
        int dp[n+1][w+1];
        for(int i=0; i<n+1; i++){
            for(int j=0; j<w+1; j++){
                if(i==0) dp[i][j]=0;
                if(j==0) dp[i][j]= 1;
            }
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<w+1; j++){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][w];
    }
};