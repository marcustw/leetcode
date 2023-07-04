class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        // find each bit where sum%3 == 1
        /*
        binary([2,2,3,2]) = [10, 10, 11, 10]
        001 -> sum = 1, sum%3 == 1
        010 -> sum = 4, sum%3 == 1
        ans = 11

        binary([0,0,0,1,1,1,15,15,15,16]) = [0, 0, 0, 1, 1, 1, 01111, 01111, 01111, 10000]
        00001 -> sum = 6, sum%3 == 0
        00010 -> sum = 3, sum%3 == 0
        00100 -> sum = 3, sum%3 == 0
        01000 -> sum = 3, sum%3 == 0
        10000 -> sum = 1, sum%3 == 1
        */
        for (int i=0; i<32; ++i) {
            int sum=0;
            int mask=1<<i;
            for (const int& n : nums) {
                if (n&mask)
                    ++sum;
            }
            if (sum%3==1)
                ans|=mask;
        }
        return ans;
    }
};