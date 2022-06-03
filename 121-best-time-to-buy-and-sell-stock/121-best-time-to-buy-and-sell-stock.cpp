class Solution {
public:
    //O(n) solution
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int profit = 0;
        for(int i = 0; i < prices.size(); i++){
            buy = min(buy, prices[i]); //keep track of lowest buy price
            profit = max(prices[i]-buy, profit); //keep track of maximum profit
        }
        return profit;
    }
};