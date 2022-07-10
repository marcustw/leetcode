class Solution {    
    bool recurse(vector<int>& arr, int i, vector<int>& visited) {
        if (i<0 || i>=arr.size()) return false;
        if (arr[i]==0) visited[i]=2;
        if (visited[i]) return visited[i]>1;
        visited[i]=1;
        if (recurse(arr,i-arr[i],visited) || recurse(arr,i+arr[i],visited)) visited[i]++;
        return visited[i]>1;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        if (arr[start]==0) return true;
        vector<int> visited=vector<int>(arr.size(), 0);
        return recurse(arr, start, visited);
    }
};