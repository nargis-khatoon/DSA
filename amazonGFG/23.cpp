//Count all possible groups of size 2 or 3 that have sum as multiple of 3
//made hashmap to store remainders of every element in array then used combinations
//to find number of groups formed
class Solution{   
public:
    long long findgroups(int arr[], int n) {
        // code here
        long long ans=0;
        map<long long, long long> c;
        for(int i=0; i<n; i++){
            c[arr[i]%3]++;
        }
        //for 2 element groups 2cases: 
        //case 1: both elements have remainder 0 
        //case 2: one element has remainder 0 and other has remainder 1
        ans+=((c[0]*(c[0]-1))>>1);
        ans+=(c[1]*c[2]);
        //for 3 element group 4cases;
        ans+=(c[0]*(c[0]-1)*(c[0]-2))/6;
        ans+=(c[1]*(c[1]-1)*(c[1]-2))/6;
        ans+=(c[2]*(c[2]-1)*(c[2]-2))/6;
        ans+=c[1]*c[2]*c[0];
        return ans;
    }
};