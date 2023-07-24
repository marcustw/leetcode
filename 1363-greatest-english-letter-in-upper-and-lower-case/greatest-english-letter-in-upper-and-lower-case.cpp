class Solution {
public:
    string greatestLetter(string s) {
        unordered_set<char> sed;
        char ans='\0';
        for (const char& c : s)
            if (islower(c)) sed.insert(c);
        for (const char& c : s)
            if (isupper(c) && sed.find(tolower(c))!=sed.end())
                ans=max(ans, c);
        return ans=='\0' ? "" : string(1, ans);
    }
};