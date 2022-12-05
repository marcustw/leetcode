class Solution {
    
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
        vector<pair<int,int>> dp(26, {-1, -1});
        for (int i=0; i<n; i++) {
            int j = s[i]-'a';
            if (dp[j].first==-1) dp[j].first = i;
            if (dp[j].second==-1) dp[j].second = i;
            if (dp[j].second < i) dp[j].second = i;
        }
        sort(dp.begin(), dp.end(), [](const auto& p1, const auto& p2) {
            return p1.first < p2.first;
        });
        vector<int> ans;
        int lo=INT_MIN, hi=INT_MAX;
        for (int i=0; i<26; i++) {
            if (dp[i].first==-1) continue; //never appeared
            if (lo==INT_MIN && hi==INT_MAX) {
                lo=dp[i].first;
                hi=dp[i].second;
            }
            if (dp[i].first > lo && dp[i].first < hi) {
                hi=max(dp[i].second, hi);
            } else if (dp[i].first > hi) {
                if (lo!=INT_MIN && hi!=INT_MAX) ans.push_back(hi-lo+1);
                lo=dp[i].first;
                hi=dp[i].second;
            }
        }
        ans.push_back(hi-lo+1);
        return ans;
    }
};