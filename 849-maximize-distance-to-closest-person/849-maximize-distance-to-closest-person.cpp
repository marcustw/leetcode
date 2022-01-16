class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int res = 0;
        int dist;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 1) {
                dist = i;
                break;
            }
        }
        
        for (int seat : seats) {
            if (seat == 1) {
                int c = ceil(dist / (double) 2);
                res = max(res, c);
                dist = 0;
            } else {
                dist += 1;
            }
        }
        return max(res, dist);
    }
};