class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size(), lo=1, hi=10000000;
        if (n-1>=hour) return -1;
        while (lo<=hi) {
            int mid=(lo+hi)/2;
            double time=0;
            for (int i=0; i<n-1; ++i) time+=ceil(((double)dist[i])/mid);
            time+=((double) dist[n-1])/mid;
            if (time>hour) lo=mid+1;
            else hi=mid-1;
        }
        return lo;
    }
};