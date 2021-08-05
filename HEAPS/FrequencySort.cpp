struct comp {
    bool operator()(pair<int, int> p1, pair<int, int> p2) {
	    // If frequncy of p1 and p2 is equal then return the greater element
        if (p1.first == p2.first) return p1.second < p2.second;
        
		// Else return the element with smaller frequency
        return p1.first > p2.first;
    }
};

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
	    // The data in priority_queue will be pair<frequency, arr[i]> as we want to sort by frequency
        priority_queue< pair<int, int>, vector<pair<int, int>>, comp > pq;
        unordered_map<int, int> mp;
        vector<int> res;
        
		// Store the frequency of elements in map
        for (int num : nums) mp[num]++;
        
		// Insert all the elements in map into min heap
        for (auto it = mp.begin(); it != mp.end(); it++) {
            pq.push({ it->second, it->first });
        }
        
		// Remove elements from heap and insert in result vector
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
			// Inserting the element top.first times, where top.first is the frequency of element
            while (top.first > 0) {
                res.push_back(top.second);
                top.first -= 1;                
            }
        }
        
        return res;
    }
};