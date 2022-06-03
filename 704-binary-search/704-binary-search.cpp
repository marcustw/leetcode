class Solution {
public:
    //O(log n)
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        while (l<=r) { //binsearch left<=right
            int i=(l+r)/2;
            if (nums[i]==target) return i;
            else if (nums[i]>target) r=i-1;
            else l=i+1;
        }
        return -1; //not found
    }
};