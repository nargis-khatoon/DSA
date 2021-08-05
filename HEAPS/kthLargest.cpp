//BRUTEFORCE SORTING 
//n log k
//explain why heap can be used- because only k are required so no need to sort completely
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //kth largest element so make use of minheap
        priority_queue<int, vector<int>, greater<int>> minheap;
        for(int i=0; i<nums.size(); i++){
            minheap.push(nums[i]);
            if(minheap.size()>k)
                minheap.pop();
            
        }
        return minheap.top();
        
    }
};