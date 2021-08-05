//missing number in an array 
class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        // Your code goes here
        long long sum=0;
        for(int i=0; i<n-1; i++){
            sum+=array[i];
        }
        long long nsum=(n*(n+1))/2;
        int ans=(int)nsum-sum;
        return ans;
    }
};