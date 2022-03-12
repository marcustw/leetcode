class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    void reverse(vector<int>& nums, int start) {
        int hi = nums.size() - 1;
        int lo = start;
        while (lo < hi) {
            swap(nums, lo, hi);
            hi--;
            lo++;
        }
    }
    
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        for (int i = n-2; i >= 0; i--) { //find the highest index i such that nums[i] < nums[i+1]
            if (nums[i] < nums[i+1]) {
                for (int j = nums.size() - 1; j >= i+1; j--) { //find the highest index j such that nums[i] < nums[j]
                    if (nums[j] > nums[i]) { //cater for non-uniqueness of nums
                        swap(nums, i, j);
                        break;
                    }
                }
                reverse(nums, i+1); //reverse everything after i
                break;
            } else if (i == 0) {
                reverse(nums, 0); //no lexicographically larger, reverse all
            }
        }
    }
};