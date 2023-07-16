class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n=req_skills.size();
        unordered_map<int, vector<int>> dp;
        dp.reserve(1<<n);
        dp[0]={};
        unordered_map<string, int> m;
        for (int i=0; i<n; ++i) m[req_skills[i]]=(1<<i);
        for (int i=0; i<people.size(); ++i) {
            int j=0;
            for (auto& skill : people[i])
                j|=m[skill];
            for (auto it=dp.begin(); it!=dp.end(); ++it) {
                int total = it->first | j;
                if (dp.find(total) == dp.end() || dp[total].size()>1+dp[it->first].size()) {
                    dp[total]=it->second;
                    dp[total].push_back(i);
                }
            }
        }
        return dp[(1<<n)-1];
    }
};