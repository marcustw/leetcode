class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n==0) return false;
        else if (n==1) return true;
        return 3486784401u % n == 0;
    }
};