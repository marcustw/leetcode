class Solution {
    vector<int> can;
    
    bool recurse(vector<int>& arr, int i) {
        if (i<0 || i>=arr.size()) return false;
        else if (can[i]) return can[i]==2;
        else if (arr[i]==0) {
            can[i]=2;
            return true;
        }
        can[i]=1;
        bool canReachZero = recurse(arr, i-arr[i]) || recurse(arr, i+arr[i]);
        if (canReachZero) can[i]++;
        return can[i]==2;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        if (arr[start]==0) return true;
        can=vector<int>(arr.size(), 0);
        return recurse(arr, start);
    }
};