class Solution {
    bool comparing(vector<int>& mt, vector<int>& ms) {
        for (int i=0; i<52; i++) {
            if (mt[i]>ms[i]) return false;
        }
        return true;
    }

    int index(const char& c) {
        return isupper(c) ? c-'A'+26 : c-'a';
    }

public:
    string minWindow(string s, string t) {
        if (s==t) return s;
        int m=s.length(), n=t.length(), lo=0, hi=0;
        string ans="";
        if (m<n) return ans;
        vector<int> mt(52,0), ms(52,0);
        for (const char &c : t) mt[index(c)]++;
        while (hi<m) {
            ms[index(s[hi++])]++;
            if (hi-lo>=n && comparing(mt, ms)) {
                while (comparing(mt, ms)) {
                    ms[index(s[lo])]--;
                    if (comparing(mt, ms)) lo++;
                    else {
                        ms[index(s[lo])]++;
                        break;
                    }
                }
                if (ans=="" || ans.length()>hi-lo)
                    ans=s.substr(lo, hi-lo);
                ms[index(s[lo++])]--;
            }
        }
        return ans;
    }
};