//FIRST OCCURRENCE OF 1
//BRUTEFORCE-> linear search
class Solution{
    public:
    int firstIndex(int arr[], int n) 
    {
        // Your code goes here
        int first=-1;
        int start=0, end=n-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(arr[mid]==1){
                first=mid;
            }
            if(arr[mid]==0){
                start=mid+1;
                
            }
            else{
                end=mid-1;
            }
        }
        return first;
    }
};