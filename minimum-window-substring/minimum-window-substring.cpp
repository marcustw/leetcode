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
        int m=s.length(), n=t.length(), lo=0, hi=0, len=-1, i;
        if (m<n) return "";
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
                if (len==-1 || len>hi-lo) {
                    i=lo;
                    len=hi-lo;
                }
                ms[index(s[lo++])]--;
            }
        }
        return len==-1 ? "" : s.substr(i, len);
    }
};