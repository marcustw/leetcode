class Solution {
public:
    
    map<int, int> mem;
    
    int climbStairs(int n) {
        if (n == 1 || n == 0) {
            return 1;
        }
        if (n < 0) {
            return 0;
        }
        if (mem[n]) {
            return mem[n];
        }
        mem[n] = climbStairs(n-1) + climbStairs(n-2);
        return mem[n];
    }
};