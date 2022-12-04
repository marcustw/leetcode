class Solution {
public:
    vector<vector<int>> reconstructMatrix(int U, int L, vector<int>& C) {
        int N = C.size();
        vector<vector<int>> ans(2, vector<int>(N, 0));
        for (int i=0; i<N; i++) {
            if (C[i] == 2) {
                ans[0][i]=1;
                ans[1][i]=1;
                U--;
                L--;            
            }
            if (C[i] == 1) {
                if (U>L) {
                    ans[0][i] = 1;
                    U--;
                } else {
                    ans[1][i] = 1;
                    L--;
                }
            }
        }
        if (U != 0 || L != 0) return vector<vector<int>>();
        return ans;

    }
};