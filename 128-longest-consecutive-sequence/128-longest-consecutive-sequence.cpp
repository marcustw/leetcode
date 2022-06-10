class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        
        unordered_map<int,int> mp;
        
        for (auto num: nums) {
            if (!mp[num]) {
                int left=mp[num-1];
                int right=mp[num+1];
                int sum=left+right+1;
                mp[num]=sum;
                ans=max(ans,sum);
                mp[num-left]=sum;
                mp[num+right]=sum;
            } else continue;
        }
        
        return ans;
    }
};