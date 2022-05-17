class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        digits[n] += 1;
        int bringOver = digits[n] > 9 ? 1 : 0;
        digits[n] %= 10;
        for (int i=n-1; i>=0; i--) {
            digits[i] += bringOver;
            if (digits[i] > 9) {
                bringOver = 1;
            } else {
                bringOver = 0;
            }
            digits[i] %= 10;
        }
        if (bringOver == 1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};