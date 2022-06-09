class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int lo=0;
        int hi=nums.size()-1;
        while (nums[lo]+nums[hi]!=target) {
            if (nums[lo]+nums[hi]>target) hi--;
            else lo++;
        }
        return vector<int>({++lo,++hi});
    }
};