class Solution {
    
    void tokenize(std::string const &str, const char delim,
            std::vector<std::string> &out) {
        // construct a stream from the string
        std::stringstream ss(str);

        std::string s;
        while (std::getline(ss, s, delim)) {
            out.push_back(s);
        }
    }
public:
    string space_delimiter = " ";
    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> m;
        for (string& path : paths) {
            size_t pos = 0;
            string p = "";
            while (path[pos] != ' ') {
                p+= path[pos++];
            }
            pos++;
            p += "/";
            path.erase(0, pos);
            vector<string> strings;
            tokenize(path, ' ', strings);
            for (string s : strings) {
                size_t ps = 0;
                string filename = "";
                string content = "";
                while (s[ps] != '(') {
                    filename += s[ps++];
                }
                while (s[++ps] != ')') {
                    content += s[ps];
                }
                m[content].push_back(p+filename);
            }
        }
        vector<vector<string>> result;
        for (auto itr = m.begin(); itr != m.end(); itr++) {
            if ((*itr).second.size() > 1)
                result.push_back((*itr).second);
        }
        return result;
    }
};