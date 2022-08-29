class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while (columnNumber > 0) {
            columnNumber--;
            int c = (columnNumber) % 26;
            ans.insert(0, 1, c + 'A');
            columnNumber /= 26;
        }
        return ans;
    }
};