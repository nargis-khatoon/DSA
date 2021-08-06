//Count of subsets with sum equal to X
//Given an array arr[] of length N and an integer X, the task is to find the number of subsets with a sum equal to X.
class Solution{   
public:
    int isSubsetSum(int n, int arr[], int sum){
        // code here 
        //INITIALISING
        int dp[n+1][sum+1];
        for(int i=0; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(i==0) dp[i][j]=0;
                if(j==0) dp[i][j]=1;
            }
        }
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j-arr[i-1]] + dp[i-1][j];
                }
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};
