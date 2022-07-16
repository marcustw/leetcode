class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> clone(nums.begin(), nums.end());
        int n=nums.size();
        int start=0;
        int end=n-1;
        for (int i=0; i<n; i++) {
            if (clone[i]==0)
                nums[end--]=0;
            else
                nums[start++]=clone[i];
        }
    }
};