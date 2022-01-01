class Solution {
public:
    int maxArea(vector<int>& height) {
        int highest = 0;
        int l = height.size();
        for (int i = 0; i < l; i++) {
            int first = height[i];
            if (first * (l - i) > highest) {
                for (int j = i +1; j < l; j++) {
                    int second = height[j];
                    int lower = second > first ? first : second;
                    if ((j - i) * lower > highest) {
                        highest = (j - i) * lower;
                    }
                }
            }
            
        }
        return highest;
    }
};