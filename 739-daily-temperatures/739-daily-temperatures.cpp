class Solution {
public:
    //monotonic decreasing stack
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n);
        stack<pair<int,int>> stek;
        stek.push({temperatures[0],0});
        for (int i=1; i<n; i++) {
            int temp=temperatures[i];
            while (!stek.empty() && temp>stek.top().first) {
                ans[stek.top().second]=i-stek.top().second;
                stek.pop();
            }
            stek.push({temp,i});
        }
        
        return ans;
    }
};