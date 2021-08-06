class Solution{

  public:
  
  vector<int> isSubsetSum(int n, int arr[], int sum){
        // code here 
        //INITIALISING
        bool dp[n+1][sum+1];
        for(int i=0; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(i==0) dp[i][j]=false;
                if(j==0) dp[i][j]=true;
            }
        }
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        vector<int> ans;
        for(int i=1; i<=sum/2; i++){
            if(dp[n][i]==true)
            ans.push_back(i);
        }
        return ans;
    }
  
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    if(n==1) return arr[0];
	    int range=0;
	    for(int i=0; i<n;  i++){
	 
	        range+=arr[i];
	    }
	    vector<int> ans=isSubsetSum(n, arr, range);
	    int mn=INT_MAX;
	    for(int i=0; i<ans.size(); i++){
	        mn=min(mn, range-2*ans[i]);   //*max_element(ans.begin(), ans.end());
	    }
	    
	    return mn;
	    
	} 
};
