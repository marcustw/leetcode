class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        digits[n] += 1;
        int bringOver = digits[n] > 9 ? 1 : 0;
        digits[n] %= 10;
        for (int i=n-1; i>=0; i--) {
            int j = digits[i];
            if (j+bringOver > 9) {
                bringOver = 1;
                digits[i] = (j+bringOver) % 10;
            } else {
                digits[i] = (j+bringOver) % 10;
                bringOver = 0;
            }
            
        }
        if (bringOver == 1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};