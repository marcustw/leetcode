class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s1=0;
        int s2=0;
        int n=nums.size();
        for (int i=0; i<n; i++) {
            s1+=nums[i];
            s2+=i;
        }
        return s2+n-s1;
    }
};