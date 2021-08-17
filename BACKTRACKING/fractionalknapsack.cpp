/*
struct Item{
    int value;
    int weight;
};
*/

bool comp(Item a, Item b){
    double r1=(double)a.value/(double)a.weight;
    double r2=(double)b.value/(double)b.weight;
    return r1>r2;
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    

    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr+n, comp);
        double currWeight=0;
        double finalVal=0.0;
        for(int i=0; i<n; i++){
            if(arr[i].weight+currWeight <= W){
                currWeight+=arr[i].weight;
                finalVal+=arr[i].value;
            }
            else{
                double remain=W-currWeight;
                finalVal+=(double)(arr[i].value/(double)arr[i].weight)*(double)remain;
                break;
            }
        }
        return finalVal;
    }

        
};