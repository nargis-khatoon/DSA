//Equilibrium index of an array
class Solution{
   public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long arr[], int n) {
    
        // Your code here
        long long sum=0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
        }
        long long leftsum=0;
        long long rightsum=sum;
        for(int i=0; i<n; i++){
            rightsum-=arr[i];
            if(rightsum==leftsum) return i+1;
            leftsum+=arr[i];
        }
        return -1;
    }
};