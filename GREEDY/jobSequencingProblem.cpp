/*
JOB SEQUENCING PROBLEM
Given a set of N jobs where each jobi has a deadline and profit associated with it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the number of jobs done and the maximum profit.
*/
bool comp(Job j1, Job j2){
    if(j1.profit>j2.profit) return true;
    return false;
}

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr+n, comp);
        //INTUITION: trying to do a job just before deadline or on deadline so we have dates for jobs with lesser deadlines to maximize profit
        //making slots for each deadline. Considering maximum deadline
        int maxD=arr[0].dead;
        for(int i=1; i<n; i++){
            maxD=max(arr[i].dead, maxD);
        }
        int slot[maxD+1]; //+1 because of 0 based indexing of arrays 
        memset(slot, -1, sizeof(slot));
        
        vector<int> ans;
        
        int profit=0, count=0;
        for(int i=0; i<n; i++){
            for(int j=arr[i].dead; j>0; j--){
                if(slot[j]!=-1) continue;
                slot[j]=arr[i].id;
                count++;
                profit+=arr[i].profit;
                break;
            }
        }
        ans.push_back(count);
        ans.push_back(profit);
        return ans;
        
        
        
    } 
};