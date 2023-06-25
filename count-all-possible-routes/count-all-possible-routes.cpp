class Solution {
    int MOD=1e9+7;

    long recurse(vector<int>& locations, int city, int finish, int fuel, vector<vector<long>>& dp) {
        if (fuel<0) return 0;
        if (dp[city][fuel]!=-1) return dp[city][fuel];
        long ans = (city==finish) ? 1L : 0L;
        for (int nextCity=0; nextCity<locations.size(); ++nextCity) {
            if (nextCity!=city) {
                ans = (ans + recurse(locations, nextCity, finish, fuel-abs(locations[city]-locations[nextCity]), dp)) % MOD;
            }
        }
        return dp[city][fuel]=ans;
    }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n=locations.size();
        vector<vector<long>> dp(n, vector<long>(fuel+1, -1L));
        return recurse(locations, start, finish, fuel, dp);
    }
};