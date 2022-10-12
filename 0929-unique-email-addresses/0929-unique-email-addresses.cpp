class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> sed;
        for (string& s : emails) {
            string e = "";
            int add;
            bool ignore = false;
            for (int i=0; i<s.length(); i++) {
                char c = s[i];
                if (c == '+') {
                    ignore = true;
                }
                if (c == '.') {
                    continue;
                }
                if (c == '@') {
                    add = i;
                    break;
                }
                if (!ignore) e += c;
            }
            e += s.substr(add);
            sed.insert(e);
        }
        for (auto itr = sed.begin(); itr != sed.end(); itr++) {
            cout << *itr << endl;
        }
        return sed.size();
    }
};