class Solution {
private:
    unordered_map<string,int> m;
    
    int recurse(vector<int>& nums, int index, int sum, int target) {
        if (index==nums.size()) return sum==target?1:0;
        string s = to_string(index) + "," + to_string(sum);
        if (m.count(s)) return m[s];
        int ans = recurse(nums,index+1,sum+nums[index],target) + recurse(nums,index+1,sum-nums[index],target);
        m[s]=ans;
        return ans;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return recurse(nums,0,0,target);
    }
};