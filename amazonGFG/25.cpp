//Count total set bits in all numbers from 1 to n
class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.

    //2^x<=n in this function
    int pow2(int n){
        int x=0;
        while((1<<x)<=n){
            x++;
        }
        return x-1;
        
    }
    int countSetBits(int n)
    {
        // Your logic here
        if(n==0) return 0;
        int x=pow2(n);
        int set_bits_till_2powx=x*(1<<x-1);  //-> x*(2^(x-1))
        int msb_from_2powx_till_n=n-(1<<x)+1; //-> n-(2^x)+1
        int rem=n-(1<<x);                     //-> n-(2^x)
        int ans=set_bits_till_2powx+msb_from_2powx_till_n+countSetBits(rem);
        return ans;
        
        
    }
};