class Solution{
	public:
   int  minimum_difference(vector<int>nums){
 	// Code here
 	int diff=INT_MAX;
 	sort(nums.begin(), nums.end());
 	for(int i=0; i<nums.size()-1; i++){
 	    if(abs(nums[i]-nums[i+1])<diff){
 	        diff=abs(nums[i]-nums[i+1]);
 	    }
 	}
 	return diff;
    }  
};