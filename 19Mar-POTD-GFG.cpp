class Solution {
    int dp[1001][201][2];
  public:
    int f(int idx,vector<int>& prices, int k,int buy)
    {
        if (idx >= prices.size() || k <= 0) return 0;
        if(dp[idx][k][buy]!=-1) return dp[idx][k][buy];
        int profit = 0;

        if (buy) {
            // Either buy the stock or skip
            profit = max(-prices[idx] + f(idx + 1, prices, k, 0), f(idx + 1, prices, k, 1));
        } else {
            // Either sell the stock (reducing k) or skip
            profit = max(prices[idx] + f(idx + 1, prices, k - 1, 1), f(idx + 1, prices, k, 0));
        }
        
        return dp[idx][k][buy] =profit;
    }
    int maxProfit(vector<int>& prices, int k) {
        // code here
        int n=prices.size();
        memset(dp, -1, sizeof(dp)); 
        return f(0,prices,k,1);
    }
};