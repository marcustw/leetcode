class Solution {
    vector<vector<int>> ans;
    
    void recurse(vector<int>& candidates, int target, int i, vector<int>& v) {
        if (target==0) {
            ans.push_back(v);
            return;
        }
        if (i==candidates.size() || target<0) return;
        int cur=candidates[i];
        v.push_back(cur);
        recurse(candidates,target-cur,i+1,v);
        v.pop_back();
        while(i<candidates.size() && candidates[i]==cur) i++;
        recurse(candidates,target,i,v);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        recurse(candidates, target, 0, v);
        return ans;
    }
};