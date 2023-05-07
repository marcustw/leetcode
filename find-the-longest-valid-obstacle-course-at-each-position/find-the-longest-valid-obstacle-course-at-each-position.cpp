class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<int> ls, ans(obstacles.begin(), obstacles.end());
        ls.push_back(ans.front());
        ans[0]=1;
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