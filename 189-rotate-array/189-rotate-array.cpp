class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> clone(n);
        for (int i=0; i<n; i++) {
            clone[i]=nums[i];
        }
        for (int i=0; i<n; i++) {
            nums[(i+k)%n]=clone[i];
        }
    }
};