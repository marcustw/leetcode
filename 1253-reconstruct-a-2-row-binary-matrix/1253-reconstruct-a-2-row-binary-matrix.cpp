class Solution {
public:
    vector<vector<int>> reconstructMatrix(int U, int L, vector<int>& C) {
        int N = C.size();
        vector<int> c1(N, 0);
        vector<int> c2(N, 0);
        for (int i=0; i<N; i++) {
            if (C[i] == 0) continue;
            if (C[i] == 2) {
                c1[i] = 1;
                c2[i] = 1;
                U--;
                L--;            
            }
        }
        for (int i=0; i<N; i++) {
            if (C[i] == 1) {
                if (U>0) {
                    c1[i] = 1;
                    U--;
                } else {
                    c2[i] = 1;
                    L--;
                }
            }
        }
        if (U != 0 || L != 0) return vector<vector<int>>();
        return {c1, c2};

    }
};