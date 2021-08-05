class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //using maxheap as maxheap pops out maximum element which are of no use to us
        priority_queue<pair<int, int>> maxheap;
        vector<vector<int>> ans;
        
        for(int i=0; i<points.size(); i++){
            int dist=(points[i][0])*(points[i][0])+(points[i][1])*(points[i][1]);
            //storing distance and index in maxheap.
            maxheap.push({dist, i});
            if(maxheap.size()>k){
                maxheap.pop();
            }
        }
        while(maxheap.size()>0){
            //the top of maxheap: first distance, second index
            ans.push_back(points[maxheap.top().second]);
            maxheap.pop();
        }
        return ans;
    }
};