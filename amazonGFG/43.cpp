//43. k largest(or smallest) elements in an array | added Min Heap method
class Solution
{
    public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        // code here
        priority_queue<int, vector<int>, greater<int>> minheap;
        int i=0;
        while(i<n){
            minheap.push(arr[i]);
            if(minheap.size()>k){
                minheap.pop();
            }
            i++;
        }
        vector<int> ans;
        
        while(minheap.size()!=0){
            int top=minheap.top();
            ans.push_back(top);
            minheap.pop();
        }
        sort(ans.begin(), ans.end(), greater<int>());
        return ans;
    }
};