//36 Count the number of possible triangles
class Solution
{
    public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
        // code here
        sort(arr, arr+n);
        int count=0;
        for(int i=n-1; i>0; i--){
            int k=i-1;
            int j=0;
            while(j<k){
                long long sum=arr[j]+arr[k];
                if(sum>arr[i])
                {
                    count+=k-j;
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return count;
    }
};