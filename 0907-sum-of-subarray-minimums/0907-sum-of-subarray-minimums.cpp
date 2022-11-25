class Solution {
    int MOD = 1000000007;
public:
    int sumSubarrayMins(vector<int>& arr) {
        int sum = 0;
        stack<int> s;
        s.push(-1);
        for (int i=0; i<arr.size()+1; i++) {
            int cur = (i<arr.size()) ? arr[i] : 0;
            while (s.top() != -1 && cur < arr[s.top()]) {
                int id = s.top();
                s.pop();
                int i2 = s.top();
                int l = id-i2;
                int r = i-id;
                long add = (long) (l * r * (long) arr[id]) % MOD;
                sum += add;
                sum %= MOD;
            }
            s.push(i);
        }
        
        return sum;
    }
};