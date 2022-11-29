class Solution {
    double dist(vector<int>& p1, vector<int>& p2) {
        return sqrt(pow(p1[0]-p2[0], 2) + pow(p1[1]-p2[1], 2));
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points = {p1, p2, p3, p4};
        unordered_set<double> s;
        for (int i=0; i<4; i++) {
            for (int j=0; j<i; j++)  {
                double d = dist(points[i], points[j]);
                if (d==0) return false;
                s.insert(d);
            }
        }
        return s.size() == 2;
    }
};