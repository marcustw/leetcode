class Solution {
public:
    // O(nlog(k)) time complexity
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int n=nums.size();
        // iterate through n elements
        for (int i=0;i<n;i++) {
            pq.push(nums[i]);
            
            // always maintaining a minHeap of k elements
            if (pq.size()>k)
                pq.pop(); // O(log k)
        }
        return pq.top();
    }
};
