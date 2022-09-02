class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> m(60, 0);
        for (int i=0; i<time.size(); i++) {
            time[i] %= 60;
            m[time[i]]++;
        }
        long long ans=0;
        for (int i=0; i<time.size(); i++) {
            int target = (60-time[i]) % 60;
            ans += m[target];
            if (time[i] == target) ans--;
        }
        return (int) (ans / 2);
    }
};
