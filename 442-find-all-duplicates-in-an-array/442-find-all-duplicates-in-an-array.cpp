class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            int j=abs(nums[i])-1;
            nums[j]*=-1;
            // if item (nums[j]) happens to be double negated, then it means j has been repeated twice.
            if (nums[j]>0) ans.push_back(abs(nums[i]));
        }
        return ans;
    }
};