class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int m=firstList.size(), n=secondList.size();
        if (m==0 || n==0) return ans;
        int i=0, j=0;
        while (i<m && j<n) {
            int start = max(firstList[i][0], secondList[j][0]);
            int end = min(firstList[i][1], secondList[j][1]);
            if (start <= end) ans.push_back({start,end});
            if (firstList[i][1] < secondList[j][1]) i++;
            else j++;
        }
        return ans;
    }
};