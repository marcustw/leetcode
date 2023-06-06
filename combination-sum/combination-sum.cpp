class Solution {
    vector<vector<int>> ans;

    void recurse(vector<int>& candidates, vector<int> path, int target, int curSum, int i) {
        if (i>=candidates.size()) return;
        path.push_back(candidates[i]);
        int newSum=candidates[i]+curSum;
        if (newSum==target) {
            ans.push_back(path);
            return;
        }
        if (newSum<target) {
            recurse(candidates, path, target, newSum, i);
        }
        path.pop_back();
        recurse(candidates, path, target, curSum, i+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        int i=0, curSum=0;
        recurse(candidates, path, target, curSum, i);
        return ans;
    }
};