class Solution {
    string removeLeadingZeroes(string num) {
        int i=0;
        while (num[i]=='0') i++;
        if (i == num.length()) return "0";
        return num.substr(i, num.length()-i);
    }

public:
    string removeKdigits(string num, int k) {
        if (num.length() <= k) return "0";
        if (k == 0) return num;
        stack<char> s;
        s.push(num[0]);
        for (int i=1; i<num.length(); i++) {
            while (k>0 && !s.empty() && num[i] < s.top()) {
                k--;
                cout << "pop: " << s.top() << endl;
                s.pop();
            }
            s.push(num[i]);
            if (s.size() == 1 && num[i] == '0') s.pop();
        }
        while (k-->0 && !s.empty()) s.pop();
        string ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        if (ans.length() == 0) return "0";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};