class Solution {
public:    
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum1=0,sum2=0;
        for (int i=0; i<n; i++) sum2+=nums[i];
        sum2-=x;
        
        if (sum2==0) return n; //sum off whole array adds up to x
        
        int i=0, ans=0;
        for (int j=0; j<n; j++) {
            sum1+=nums[j];
            while (i<n && sum1>sum2) sum1-=nums[i++];
            if (sum1==sum2) ans=max(ans,j-i+1);
        }
        return ans==0 ? -1 : n-ans;
    }
};
