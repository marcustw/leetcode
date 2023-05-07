class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<int> ls, ans(n, 1);
        ls.push_back(obstacles.front());
        for (int i=1; i<n; i++) {
            int val=obstacles[i];
            if (ls.back() <= val) {
                ls.push_back(val);
                ans[i]=ls.size();
            } else {
                int idx = upper_bound(ls.begin(), ls.end(), val) - ls.begin();
                ls[idx]=val;
                ans[i]=idx+1;
            }
        }
        return ans;
    }
};