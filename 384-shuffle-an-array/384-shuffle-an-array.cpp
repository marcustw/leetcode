class Solution {
    vector<int> origin;
    int n;
public:
    
    Solution(vector<int>& nums) {
        origin=nums;
        n=nums.size();
    }
    
    vector<int> reset() {
        return origin;
    }
    
    vector<int> shuffle() {
        vector<int> shuffled(origin);
        for (int i=0; i<n; i++) {
            int j=rand()%n;
            swap(shuffled[i], shuffled[j]);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */