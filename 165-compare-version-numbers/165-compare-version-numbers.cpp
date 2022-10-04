class Solution {
    int strToInt(string i) {
        int id = 0;
        while (i[id] == '0') id++;
        if (id == i.length()) return 0;
        return stoi(i.substr(id, i.length()));
    }
public:
    int compareVersion(string version1, string version2) {
        istringstream iss(version1);
        vector<string> tokens;
        string token;
        while (std::getline(iss, token, '.')) {
            if (!token.empty())
                tokens.push_back(token);
        }
        istringstream iss2(version2);
        vector<string> tokens2;
        while (std::getline(iss2, token, '.')) {
            if (!token.empty())
                tokens2.push_back(token);
        }
        int size1 = tokens.size();
        int size2 = tokens2.size();
        int size = min(size1, size2);
        if (size1 == 0 && size2 == 0) {
            return size1 == size2 ? 0 : size1 < size2 ? -1 : 1;
        }
        for (int i=0; i<size; i++) {
            int s1 = strToInt(tokens[i]);
            int s2 = strToInt(tokens2[i]);
            if (s1 < s2) return -1;
            else if (s1 > s2) return 1;
        }
        if (size1 < size2) {
            for (int i = size; i < size2; i++) {
                if (strToInt(tokens2[i]) > 0) return -1; 
            }
        }
        else {
            for (int i = size; i < size1; i++) {
                if (strToInt(tokens[i]) > 0 ) return 1;
            }
        }
        return 0;
    }
};