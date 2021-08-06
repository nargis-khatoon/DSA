//494. Target Sum
//You are given an integer array nums and an integer target.

//You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
class Solution {
public:
    
    int countSubsets(vector<int> arr, int sum){
        // code here 
        //INITIALISING
        int n=arr.size();
        int dp[n+1][sum+1];
        for(int i=0; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(i==0) dp[i][j]=0;
                if(j==0) dp[i][j]=1;
            }
        }
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(arr[i-1]==0){
                    dp[i][j]=dp[i-1][j];
                }
                else if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j-arr[i-1]] + dp[i-1][j];
                }
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        //S1-S2=TARGET
        /*
            S1-S2=target
            S1+S2=sum
            2S1=target+sum
            S1=(target+sum)/2
        */
        int n=nums.size();
        
        int sum=0;
        int count_0=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            if(nums[i]==0)
                count_0++;
        }
        int S1=(target+sum)/2;
        int ans=countSubsets(nums, S1);
        if(sum < target || (sum + target)%2 == 1){
            return 0;
        }
        return pow(2, count_0)*ans;
        
    }
};