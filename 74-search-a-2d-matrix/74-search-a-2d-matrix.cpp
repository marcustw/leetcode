class Solution {
private:
    bool binSearch(vector<int>& arr, int target, int n) {
        int lo=0;
        int hi=n-1;
        while(lo<=hi) {
            int mid=(lo+hi)/2;
            if (arr[mid]==target) return true;
            if (target<arr[mid]) hi=mid-1;
            else lo=mid+1;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int u=0;
        int d=m-1;
        while (u<d) {
            int mid=(u+d)/2;
            int m0=matrix[mid][0];
            int m1=matrix[mid][n-1];
            if (target>=m0 && target<=m1) {
                return binSearch(matrix[mid],target,n);
            }
            if (target>m1) u=mid+1;
            else d=mid-1;
        }
        return binSearch(matrix[u],target,n);
    }
};