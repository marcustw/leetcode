class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1, 0);
        ans[0] = 1;
        for (int i=1; i<rowIndex+1; i++) {
            for (int j=i-1; j>=1; j--) {
                ans[j] += ans[j-1];
            }
            ans[i]=1;
        }
        return ans;
    }
};