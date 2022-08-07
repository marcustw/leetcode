class Solution {
public:
    // sum contribution of each element to uniqueCharCount
    int uniqueLetterString(string s) {
        int n=s.length(), ans=0;
        vector<vector<int>> pos(26, {-1});
        for (int i=0; i<n; i++) {
            pos[s[i]-'A'].push_back(i);
        }
        for (int x=0; x<26; x++) {
            pos[x].push_back(n);
            for (int i=1; i<pos[x].size()-1; i++) {
                int lo=i-1, hi=i+1;
                ans += (pos[x][i]-pos[x][lo]) * (pos[x][hi]-pos[x][i]);
            }
        }
        
        return ans;
    }
};