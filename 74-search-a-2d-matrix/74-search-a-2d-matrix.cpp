class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int lo=0, hi=m*n-1;
        while (lo<hi){
            int mid=(lo+hi)/2;
            if (matrix[mid/m][mid%m]<target)
                lo=mid+1;
            else 
                hi=mid;
        }
        return matrix[hi/m][hi%m] == target;
    }
};