class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0;
        int l = flowerbed.size();
        if (l == 1 && n == 1 && flowerbed[i] == 0) return true;
        while (n > 0 && i < l) {
            if (i == 0) {
                if (flowerbed[i] == 0 && flowerbed[i+1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            } else if (i == l-1) {
                if (flowerbed[i] == 0 && flowerbed[i-1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            } else if (flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0) {
                flowerbed[i] = 1;
                n--;
            }
            if (flowerbed[i] == 1) {
                i += 2;
            } else {
                i++;
            }
        }
        return n == 0;
    }
};