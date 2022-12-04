class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        if (n==1) return 0;
        long sum=0, curSum=0;
        for (const int& i : nums) sum+=i;
        int lowest=INT_MAX;
        int ans=0;
        for (int i=0; i<n-1; i++) {
            curSum += nums[i];
            int avg = curSum / (i+1);
            int avg2 = (sum-curSum) / (n-i-1);
            int diff = abs(avg-avg2);
            if (diff < lowest) {
                lowest = diff;
                ans = i;
            }
        }
        if ((curSum + nums[n-1]) / n < lowest) {
            return n-1;
        }
        return ans;
    }
};