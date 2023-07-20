class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0, hold=INT_MIN, noHold=0;

        for (const int& price : prices) {
            int prevHold = hold, prevNoHold=noHold;
            hold=max(prevHold, prevNoHold-price);
            noHold=max(prevNoHold, prevHold+price);
            ans=max(hold, noHold);
        }

        return ans;
    }
};