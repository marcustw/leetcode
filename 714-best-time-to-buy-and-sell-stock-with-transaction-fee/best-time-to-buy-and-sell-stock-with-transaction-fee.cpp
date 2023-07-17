class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.size()<=1) return 0;
        int sell=0, buy=INT_MIN;
        for (const int& price : prices) {
            buy=max(buy, sell-price);
            sell=max(sell, buy+price-fee);
        }
        return sell;
    }
};