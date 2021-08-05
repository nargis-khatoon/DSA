int minMoves(int a[], int n)
{
    int i=0;
    int itr=0;
    bool found1=false;
    int maxitr=INT_MIN;
    while(i<n){
        int count0=0;
        if(a[i]==1){
            found1=true;
        }
        while(i<n && a[i]==1){
            i++;
        }
        while(i<n && a[i]==0){
            count0++;
            i++;
        }
        
        if(found1==false && i==n) return -1;
        
        int curr_count;
        if (i < n && found1 == true)
        {
            // If count_zero is even
            if (count0 & 1 == 0)
                curr_count = count0/2;
 
            // If count_zero is odd
            else
                curr_count = (count0+1)/2;
 
            // Reset count_zero
            count0 = 0;
        }
 
        // Case 2
        else
        {
            curr_count = count0;
            count0 = 0;
        }
 
        // Update res
        maxitr = max(maxitr, curr_count);
    }
 
    return maxitr;
}
