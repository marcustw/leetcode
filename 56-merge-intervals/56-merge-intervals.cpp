class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> result;
        
        int curBegin = intervals[0][0];
        int curEnd = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > curEnd) {
                result.push_back({curBegin, curEnd});
                curBegin = intervals[i][0];
                curEnd = intervals[i][1];
            } else {
                curEnd = max(curEnd, intervals[i][1]);
            }
        }
        result.push_back({curBegin, curEnd});
        
        return result;
    }
};