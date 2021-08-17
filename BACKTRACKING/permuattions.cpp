//46. Permutations
// https://leetcode.com/problems/permutations/
//Given an array nums of distinct integers, return all the possible permutations. 
//You can return the answer in any order.
class Solution {
public:
    vector<vector<int>> ans;
    void solve(int start, vector<int> perm, vector<int>& nums){
        if(start==nums.size()){
            ans.push_back(perm);
            return;
        }
        
        for(int i=start; i<nums.size(); i++){
            swap(nums[i], nums[start]);
            perm=nums;
            solve(start+1, perm, nums);
            swap(nums[i], nums[start]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> perm;
        solve(0, perm, nums);
        return ans;
    }
};