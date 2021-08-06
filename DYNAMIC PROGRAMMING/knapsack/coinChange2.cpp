class Solution
{
public:
    int minCoins(int arr[], int M, int V)
    {
        // Your code goes here
        int n = M, sum = V;
        int t[n + 1][sum + 1];
        //initialization
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (j == 0)
                    t[i][j] = 0;
                if (i == 0)
                    t[i][j] = INT_MAX - 1;
            }
        }
        //unbounded knapsack code
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (arr[i - 1] <= j)
                {
                    t[i][j] = min(t[i - 1][j], t[i][j - arr[i - 1]] + 1);
                }
                else
                    t[i][j] = t[i - 1][j];
            }
        }
        if (t[n][sum] > sum)
            return -1;
        else
            return t[n][sum];
    }
};