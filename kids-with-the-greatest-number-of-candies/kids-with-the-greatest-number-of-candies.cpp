class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size(), largest=INT_MIN;
        vector<bool> ans;
        for (const int& c : candies) largest=max(largest,c);
        for (const int& c : candies) ans.push_back((c+extraCandies>=largest));
        return ans;
    }
};