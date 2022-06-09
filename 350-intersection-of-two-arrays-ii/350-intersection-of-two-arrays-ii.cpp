class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        if (m<n) {
            return intersect(nums2,nums1);
        }
        unordered_map<int,int> mep;
        for (int i=0; i<m; i++) {
            mep[nums1[i]]++;
        }
        vector<int> ans;
        for (int j=0; j<n; j++) {
            int x=nums2[j];
            if (mep.count(x) && mep[x]) {
                mep[x]--;
                ans.push_back(x);
            }
        }
        return ans;
    }
};