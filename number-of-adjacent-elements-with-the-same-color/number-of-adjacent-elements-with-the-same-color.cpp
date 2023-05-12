ostream& operator<<(ostream& os, const vector<int>& v) {
    for (int i=0; i<v.size(); i++) os << v[i] << (i==v.size()-1? "": ", ");
    return os;
}
class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> ans, colors(n, 0);
        int count=0;
        for (auto q : queries) {
            int i=q[0], c=q[1];
            if (colors[i] && i>0 && colors[i-1]==colors[i]) count--;
            if (colors[i] && i<n-1 && colors[i+1]==colors[i]) count--;
            colors[i]=c;
            if (i>0 && colors[i-1]==colors[i]) count++;
            if (i<n-1 && colors[i+1]==colors[i]) count++;
            ans.push_back(count);
        }
        return ans;
    }
};