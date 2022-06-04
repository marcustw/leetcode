class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i=0;
        while(i<intervals.size() && intervals[i][1]<newInterval[0]) {
            ans.push_back(intervals[i++]);
        }
        int f=newInterval[0];
        int t=newInterval[1];
        while(i<intervals.size() && intervals[i][0]<=t) {
            int f2=intervals[i][0];
            int t2=intervals[i][1];
            f=min(f,f2);
            t=max(t,t2);
            i++;
        }
        ans.push_back({f,t});
        while(i<intervals.size()) {
            ans.push_back(intervals[i++]);
        }
        return ans;
    }
};