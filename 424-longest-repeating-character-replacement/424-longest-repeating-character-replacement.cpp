class Solution {
private:
    static bool compare(const pair<int,int>&a, const pair<int,int>&b) {
       return a.second<b.second;
    }
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        unordered_map<int,int> m;
        int i=0;
        for (int j=0; j<s.length(); j++) {
            m[s[j]]++;
            int cmax=max_element(m.begin(),m.end(),compare)->second;
            if (j-i+1-cmax>k) {
                m[s[i]]--;
                i++;
            } else ans=max(ans,j-i+1);    
        }
        return ans;
    }
};