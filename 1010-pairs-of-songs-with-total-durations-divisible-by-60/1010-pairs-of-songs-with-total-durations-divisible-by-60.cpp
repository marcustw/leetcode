class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, vector<int>> m;
        for (int i=0; i<time.size(); i++) {
            time[i] %= 60;
            m[time[i]].push_back(i);
        }
        long ans=0;
        for (int i=0; i<time.size(); i++) {
            int target = (60-time[i]) % 60;
            ans += m[target].size();
            if (time[i] == target) ans--;
        }
        return (int) (ans / 2);
    }
};

// 30, 20, 30, 40, 40