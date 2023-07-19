class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if (n<=2) return n;
        int i=1, j=1, c=1;
        while (j<n) {
            if (nums[j] != nums[j-1]) {
                c=1;
                nums[i++]=nums[j];
            } else if (c<2) {
                nums[i++]=nums[j];
                c++;
            }
            ++j;
        }
        return i;
    }
};