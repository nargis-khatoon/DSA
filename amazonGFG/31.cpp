//BINARY SEARCH
int binarySearch(int arr[], n)
{
    int high=0;
    int low=n-1;
    while(high >= low)
    {
        int mid = (low + high)/2; // low + (high - low)/2
        if(mid == arr[mid])
            return mid;
        if(mid > arr[mid])
            {
                //move right
                high=mid+1;
            }
        else
            {
                //move left
                low=mid-1;
            }
    }
 
    // Return -1 if there is no Fixed Point
    return -1;
}