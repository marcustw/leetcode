class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size();
        unordered_map<string, unordered_map<string, double>> m;
        for (int i=0; i<n; i++) {
            double v=values[i];
            string numer=equations[i][0], denom=equations[i][1];
            m[numer][denom] = v;
            m[denom][numer] = 1/v;
            m[numer][numer] = 1.0;
            m[denom][denom] = 1.0;
        }
        for (auto& i : m) {
            for (auto& j : m[i.first]) {
                for (auto& k : m[i.first]) {
                    m[j.first][k.first] = m[j.first][i.first] * m[i.first][k.first];
                }
            }
        }
        vector<double> ans;
        for (auto& query : queries) {
            string numer=query[0], denom=query[1];
            if (m.find(numer) != m.end() && m[numer].find(denom) != m[numer].end()) {
                ans.push_back(m[numer][denom]);
            } else {
                ans.push_back(-1.0);
            }
        }
        return ans;
    }
};