class Solution {
    
public:
    
    void generate(int start, vector<int> subsets, vector<vector<int>>& ans, vector<int> &nums){
        ans.push_back(subsets);
        
        for(int i=start; i<nums.size(); i++){
            if(i>start && nums[i]==nums[i-1])
                continue;
            subsets.push_back(nums[i]);
            generate(i+1, subsets, ans, nums);
            subsets.pop_back();
        }
       
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subsets;
        sort(nums.begin(), nums.end());
        generate(0, subsets, ans, nums);
        return ans;
        
    }
};