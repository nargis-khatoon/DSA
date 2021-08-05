//Find two prime numbers with given sum
class Solution{
	public:
   	vector<int> prime_pairs(int n){
   	    // Code here
   	    bool isPrime[n];
   	    memset(isPrime, true, n);
   	    isPrime[0]=false;
   	    isPrime[1]=false;
   	    
   	    for(int i=2; i<=sqrt(n); i++){
   	        if(isPrime[i]){
   	            for(int j=2; i*j<=n; j++){
   	                isPrime[i*j]=false;
   	            }
   	        }
   	    }
   	    vector<int> ans;
   	    for(int i=2; i<=n; i++){
   	        for(int j=2; j<=n; j++){
   	            if(i*j<=n && isPrime[i] && isPrime[j]){
   	                ans.push_back(i);
   	                ans.push_back(j);
   	            }
       	    }
   	    }
  
   	    return ans;
   	    
    }    
};