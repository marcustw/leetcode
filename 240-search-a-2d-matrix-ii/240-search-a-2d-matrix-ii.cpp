class Solution {
private:
    // Divide & Conquer
    bool recurse(vector<vector<int>>& M, int target, int p, int q, int i, int j) {
        if (p > i || q > j) return false;
        
        int midRow = p + (i - p) / 2;
        int midCol = q + (j - q) / 2;
        int mid = M[midRow][midCol];
        
        if (target == mid) return true;
        if (target < mid) {
            return  recurse(M, target, midRow, q, i, midCol - 1) ||
                    recurse(M, target, p, midCol, midRow - 1, j) ||
                    recurse(M, target, p, q, midRow - 1, midCol - 1);
        }
        return recurse(M, target, midRow + 1, q, i, midCol) ||
               recurse(M, target, p, midCol + 1, midRow, j) ||
               recurse(M, target, midRow + 1, midCol + 1, i, j);
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        return recurse(matrix, target, 0, 0, m - 1, n - 1);
    }
    
};