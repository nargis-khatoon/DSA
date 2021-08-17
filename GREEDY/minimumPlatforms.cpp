//MINIMUM PLATFORMS
/*
Given arrival and departure times of all trains that reach a railway station.
Find the minimum number of platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure 
time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. 
At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. 
In such cases, we need different platforms.


*/

classSolution{

    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	int platform=0;
    	int maxPlatform=INT_MIN;
    	int i=0; int j=0;
    	while(i<n){
    	    if(dep[j]<arr[i])
    	    {
    	        j++;
    	        if(platform>0) platform--;
    	    }
    	    else{
    	        platform++;
    	        maxPlatform=max(platform, maxPlatform);
    	        i++;
    	    }
    	}
    	return maxPlatform;
    }
};