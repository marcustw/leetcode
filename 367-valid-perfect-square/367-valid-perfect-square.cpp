class Solution {
public:
    bool isPerfectSquare(int num) {
        long l=1, r=num;
        while (l<=r) {
            long m=(l+r)/2;
            if (m*m==num) return true;
            else if (m*m>num) r=m-1;
            else l=m+1;
        }
        return false;
    }
};