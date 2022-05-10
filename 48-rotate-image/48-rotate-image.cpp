class Solution {
public:
    void swap(vector<vector<int>>& matrix, int x1, int y1, int x2, int y2) {
        int from = matrix[x1][y1];
        matrix[x1][y1] = matrix[x2][y2];
        matrix[x2][y2] = from;
    }
    
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // layer by layer
        int layers = ceil(n/2);
        for (int i=0; i<layers; i++) {
            for (int j=i; j<n-i-1; j++) {
                int offset = j;
                
                int last = n-1-i;
                //swap with R
                swap(matrix, i, j, offset, last);
                
                //swap with B
                swap(matrix, i, j, last, n-1-offset);
                
                //swap with L
                swap(matrix, i, j, n-1-offset, i);
            }
        }
    }
};