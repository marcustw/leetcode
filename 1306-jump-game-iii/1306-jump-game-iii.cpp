class Solution {
    bool recurse(vector<int>& arr, int i) {
        if (i<0 || i>=arr.size()) return false;
        if (arr[i]<0) return false;
        if (arr[i]==0) return true;
        arr[i]=-arr[i];
        return recurse(arr,i-arr[i]) || recurse(arr,i+arr[i]);
    }
public:
    bool canReach(vector<int>& arr, int start) {
        return recurse(arr,start);
    }
};