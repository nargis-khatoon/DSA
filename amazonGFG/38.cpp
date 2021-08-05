//Exceptionally odd
//BRUTEFORCE-> sort and count linearly. BETTER-> hash map 
//BEST->
class Solution{   
public:
    int getOddOccurrence(int arr[], int n) {
        // code here
        int ans=0;
        for(int i=0; i<n; i++){
            ans=ans^arr[i];
        }
        return ans;
    }
};