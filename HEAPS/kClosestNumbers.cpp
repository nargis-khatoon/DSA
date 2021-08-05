//store pair of difference between element and target
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> maxheap;
        vector<int> ans;
        for(int i=0; i<arr.size(); i++){
            maxheap.push({abs(arr[i]-x),arr[i]} );
            if(maxheap.size()>k){
                maxheap.pop();
            }
        }
        while(maxheap.size()>0){
            auto it= maxheap.top();
            maxheap.pop();
            ans.push_back(it.second);
        }
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};