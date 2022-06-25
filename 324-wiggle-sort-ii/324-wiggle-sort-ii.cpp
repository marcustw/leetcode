class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(),sorted.end());
        int n=nums.size();
        int lo=n%2==0 ? n/2-1 : n/2;
        int hi=n-1;
        for (int i=0; i<n; i+=2) {
            swap(nums[i],sorted[lo--]);
        }
        for (int i=1; i<n; i+=2) {
            swap(nums[i],sorted[hi--]);
        }
    }
};

// 1 1 1 4 5 6
// 1   1   1
//   6   5   4
