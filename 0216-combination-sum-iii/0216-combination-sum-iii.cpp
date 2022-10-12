class Solution {
    vector<vector<int>> ans;
    
    void recurse(vector<int> arr, int n, int k, int sum) {
        if (arr.size() > k || sum > n) {
            return;
        }
        if (arr.size() == k && sum == n) {
            ans.push_back(arr);
        }
        for (int i=arr.back()+1; i<=9; i++) {
            arr.push_back(i);
            recurse(arr, n, k, sum+i);
            arr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr;
        for (int i=1; i<=9; i++) {
            arr.push_back(i);
            recurse(arr, n, k, i);
            arr.pop_back();
        }
        return ans;
    }
};