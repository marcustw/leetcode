class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = 0;
        for (int pile : piles) {
            if (pile > hi) {
                hi = pile;
            }
        }
        if (piles.size() == h) return hi;
        while (lo <= hi) {
            int m = (lo + hi) / 2;
            int count = 0;
            for (int pile : piles) {
                count += ceil(1.0 * pile / m);
            }
            if (count > h) {
                lo = m + 1;
            } else {
                hi = m - 1;
            }
        }
        return lo;
    }
};