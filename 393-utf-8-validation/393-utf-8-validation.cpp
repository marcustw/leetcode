class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int ans = 0;
        for (auto& c : data) {
            if (ans == 0) {
                                // 110
                if ((c >> 5) == 6) ans = 1;
                                // 1110
                else if ((c >> 4) == 14) ans = 2;
                                // 11110
                else if ((c >> 3) == 30) ans = 3;

                // 1 byte, cannot start with 1
                else if ((c >> 7) == 1) return false;
            } else {
                //              10
                if ((c >> 6) != 2) return false;
                ans--;
            }
        }
        return ans == 0;
    }
};