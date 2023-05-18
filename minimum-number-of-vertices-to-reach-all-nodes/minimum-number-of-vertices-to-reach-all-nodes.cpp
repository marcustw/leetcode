class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        set<int> s;
        for (int i=0; i<n; i++) s.insert(i);
        for (vector<int>& e : edges) {
            if (s.find(e[1]) != s.end()) s.erase(e[1]);
        }
        return vector<int>(s.begin(), s.end());
    }
};