class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0;
        vector<int> buy(n,INT_MIN);
        vector<int> sell(n, INT_MIN);
        buy[0]=-1*prices[0];
        sell[0]=0;
        for (int i=1; i<n; i++) {
            if (i==1) {
                buy[i]=max(-1*prices[i],buy[i-1]);
            } else {
                buy[i]=max(sell[i-2]-prices[i],buy[i-1]);
            }
            sell[i]=max(buy[i-1]+prices[i],sell[i-1]);
            ans=max(buy[i],sell[i]);
        }
        return ans;
    }
};