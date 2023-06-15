class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        sort(products.begin(), products.end());
        string cur="";
        for (char& c : searchWord) {
            cur+=c;
            vector<string> suggestions;
            auto it=lower_bound(products.begin(), products.end(), cur);
            for (int i=0; i<3 && it+i!=products.end(); ++i) {
                string& s = *(it+i);
                if (s.find(cur)!=0) break;
                suggestions.push_back(s);
            }
            ans.push_back(suggestions);
        }
        return ans;
    }
};