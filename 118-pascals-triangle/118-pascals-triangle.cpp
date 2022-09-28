class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for (int i=1; i<numRows; i++) {
            vector<int> prev = ans[ans.size()-1];
            vector<int> to = {1};
            for (int j=1; j<i; j++) {
                to.push_back(prev[j-1] + prev[j]);
            }
            to.push_back(1);
            ans.push_back(to);
        }
        
        return ans;
    }
};