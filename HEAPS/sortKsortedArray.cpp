//an element that should be in ith index when sorted, is present at i-k or i+k index
//minheap pops smallest element
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //kth largest element so make use of minheap
        priority_queue<int, vector<int>, greater<int>> minheap;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            minheap.push(nums[i]);
            if(minheap.size()>k)
                {
                    ans.push_back(minheap.top());
                    minheap.pop();
                }
            
        }
        return ans;
        
    }
};