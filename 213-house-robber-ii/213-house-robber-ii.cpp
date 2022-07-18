class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        int n=nums.size();
        int curMax=0, prevMax=0, prevMax2=0, curMax2=0;
        for (int i=0; i<n; i++) {
            if (i>=0 && i<n-1) { //skip last (circular array)
                int temp=curMax;
                curMax=max(prevMax+nums[i],curMax);
                prevMax=temp;
            }
            if (i>0) { // skip first (circular array)
                int temp2=curMax2;
                curMax2=max(prevMax2+nums[i],curMax2);
                prevMax2=temp2;
            }
        }
        return max(curMax,curMax2);
    }
};