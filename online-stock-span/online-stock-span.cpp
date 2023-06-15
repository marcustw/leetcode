class StockSpanner {
    stack<pair<int,int>> s;
public:
    StockSpanner() {}

    int next(int price) {
        int ans=1;
        if (s.empty() || s.top().first>price) {
            s.push({price, ans});
            return ans;
        }
        while (!s.empty() && s.top().first<=price) {
            ans+=s.top().second;
            s.pop();
        }
        s.push({price, ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */