class Solution {
    vector<bool> visited;
    vector<bool> can;
    
    bool recurse(vector<int>& arr, int i) {
        if (i<0 || i>=arr.size()) return false;
        else if (visited[i]) return can[i];
        else if (arr[i]==0) {
            visited[i]=true;
            can[i]=true;
            return true;
        }
        visited[i] = true;
        can[i] = recurse(arr, i-arr[i]) || recurse(arr, i+arr[i]);
        return can[i];
    }
public:
    bool canReach(vector<int>& arr, int start) {
        if (arr[start]==0) return true;
        visited=vector<bool>(arr.size(), false);
        can=vector<bool>(arr.size(), false);
        return recurse(arr, start);
    }
};