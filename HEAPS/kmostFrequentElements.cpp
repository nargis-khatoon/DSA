//347. Top K Frequent Elements Leetcode: medium
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
        for(auto it: mp){
            //inserting frequency as first and element as second
            minheap.push({it.second, it.first});
            if(minheap.size()>k){
                minheap.pop();
            }
        }
        vector<int> ans;
        while(minheap.size()>0){
            pair<int, int> ele=minheap.top();
            minheap.pop();
            ans.push_back(ele.second);
        }
        return ans;
    }
};