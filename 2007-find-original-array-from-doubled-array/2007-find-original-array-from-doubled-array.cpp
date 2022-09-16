class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n % 2 != 0) return vector<int>();
        sort(changed.begin(), changed.end());
        unordered_map<int, int> m;
        vector<int> ans;
        for (int i=0; i<n; i++) {
            m[changed[i]]++;
        }
        int j = 0;
        while (j < n && ans.size() != n/2) {
            if (m[changed[j]] && m[changed[j]*2]) {
                m[changed[j]]--;
                m[changed[j]*2]--;
                if (m[changed[j]] >= 0) {
                    ans.push_back(changed[j]);
                }
            }
            j++;
        }
        if (ans.size() == n/2) return ans;
        return vector<int>();
    }
};