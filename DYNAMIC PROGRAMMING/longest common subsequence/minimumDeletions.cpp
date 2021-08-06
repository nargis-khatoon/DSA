//Minimum deletions
//SAME CODE FOR MINIMUM INSERTIONS
//Given a string of S as input. Your task is to write a program to remove or delete the minimum number of characters from the string so that the resultant string is a palindrome.

class Solution{
  public:
  
  int lps(int x, int y, string s1, string s2) //string2=reverse(string1)
    {
        // your code here
        int dp[x+1][y+1];
        for(int i=0; i<x+1; i++){
            for(int j=0; j<y+1; j++){
                if(i==0 || j==0) dp[i][j]=0;
            }
        }
        for(int i=1; i<x+1; i++){
            for(int j=1; j<y+1; j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[x][y];
    }
  
    int minimumNumberOfDeletions(string S) { 
        // code here
        int n=S.length();
        string S2= S;
        //reverse S2
        for(int i=0; i<n/2; i++){
            swap(S2[i], S2[n-(i+1)]);
        }
        return n-lps(n, n, S, S2);
    } 
};