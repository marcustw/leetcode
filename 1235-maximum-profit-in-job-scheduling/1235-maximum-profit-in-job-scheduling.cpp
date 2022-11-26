class Solution {
    typedef struct Job {
        int start;
        int end;
        int profit;
        Job(int start, int end, int profit): start(start), end(end), profit(profit) {}
        
        string toString() {
            return "Start = " + to_string(start) + ", end = " + to_string(end) + ": profit = " + to_string(profit);
        }
    } Job;
public:
    // knapsack problem
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        map<int, int> dp;
        dp[0] = 0;
        vector<Job> jobs;
        for (int i=0; i<n; i++) {
            jobs.push_back(Job(startTime[i], endTime[i], profit[i]));
        }
        sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
            return a.end == b.end ? a.start < b.start : a.end < b.end;
        });
        for (auto& job : jobs) {
            int cur = prev(dp.upper_bound(job.start))->second + job.profit;
            if (cur > dp.rbegin()->second) {
                dp[job.end] = cur;
            }
        }
        return dp.rbegin()->second;
    }
};