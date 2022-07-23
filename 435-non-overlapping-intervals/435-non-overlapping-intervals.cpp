class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& first, vector<int>& second) {
                 return first[1]<second[1];
             });
        int end=intervals[0][1];
        for (int i=1; i<intervals.size(); i++) {
            if (end>intervals[i][0]) ans++;
            else end=intervals[i][1];
            
        }
        return max(0,ans);
    }
};