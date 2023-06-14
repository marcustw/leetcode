class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        if (n<3) return false;
        int a=INT_MAX, b=INT_MAX;
        for (int& num : nums) {
            if (num<=a) a=num;
            else if (num<=b) b=num;
            else return true;
        }
        return false;
    }
};