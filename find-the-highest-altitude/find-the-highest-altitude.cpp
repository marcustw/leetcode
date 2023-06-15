class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0, count=0;
        for (const int& g : gain) {
            count+=g;
            ans=max(count, ans);
        }
        return ans;
    }
};