//FIRST AND LAST OCCURRENCE
{
    // code here
    //BINARY SEARCH
    vector<int> ans;
    int first=-1, last=-1;
    int start=0;
    int end=n-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==x){
            first=mid;
        }
        if(arr[mid]<x){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        
    }
        start=0;
        end=n-1;
        while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==x){
            last=mid;
        }
        if(arr[mid]<=x){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        
    }
    ans.push_back(first);
    ans.push_back(last);
    return ans;
}