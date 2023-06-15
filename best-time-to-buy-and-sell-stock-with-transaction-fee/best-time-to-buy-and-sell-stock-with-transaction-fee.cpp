class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.size()<=1) return 0;
        int profits=0, buy=INT_MIN;
        for (const int& p : prices) {
            int tmp=profits;
            profits=max(profits, buy+p);
            buy=max(buy, profits-p-fee);
        }
        return profits;
    }
};