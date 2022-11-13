class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string delimiter = " ";
        size_t x;
        while ((x = s.find(delimiter)) != std::string::npos) {
            string sub = s.substr(0,x);
            if (x != 0) {
                ans = sub + delimiter + ans;
            }
            s.erase(0, x+1);
        }
        if (s != "") {
            ans = s + delimiter + ans;
        }
        return ans.substr(0, ans.length()-1);
    }
};