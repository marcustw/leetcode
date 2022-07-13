class Solution {
    typedef vector<pair<int,int>>::iterator it;
public:    
    void recurse(it l, it r, vector<int>& ans) {
        if (r-l<=1) return;
        it m=l+(r-l)/2;
        recurse(l, m, ans);
        recurse(m, r, ans);
        for (it i=l, j=m; i<m; i++) {
            while (j<r && (*j).first<(*i).first) j++;
            ans[(*i).second] += j-m;
        }
        inplace_merge(l, m, r);
    }
    
    //return num of js such that i<j && nums[j]<nums[i]
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> ns(n);
        for (int i = 0; i < n; ++i) ns[i]={nums[i], i};
        vector<int> ans(n,0);
        recurse(ns.begin(), ns.end(), ans);
        return ans;
    }
};