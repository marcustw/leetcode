class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(), ans=nums[0], curMax=nums[0], curMin=nums[0];
        for (int i=1; i<n; i++) {
            int cur=nums[i];
            int mini=cur*curMin;
            int maxi=cur*curMax;
            int arr[] = {cur,mini,maxi};
            curMax=*max_element(arr,arr+3);
            curMin=*min_element(arr,arr+3);
            ans=max(curMax,ans);
        }
        return ans;
    }
};