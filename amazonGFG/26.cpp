class Solution{
    public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    //2 pointer approah. fix i at 0 and run loop till n-2. 
	    //fix 2 pointers j=i+1, k=n-1
	    long long count=0;
	    sort(arr, arr+n);
	    for(int i=0; i<n-1; i++){
	        int j=i+1, k=n-1;
	        while(j<k){
	            if(arr[i]+arr[j]+arr[k]>=sum) k--;
    	        else{
    	            count+=k-j;
    	            j++;
    	        }
	        }
	        
	        
	    }
	    return count;
	}
};