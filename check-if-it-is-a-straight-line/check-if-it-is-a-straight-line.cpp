class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int dx=coordinates[0][0]-coordinates[1][0];
        int dy=coordinates[0][1]-coordinates[1][1];
        int n=coordinates.size();
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                int xdiff=coordinates[i][0]-coordinates[j][0];
                int ydiff=coordinates[i][1]-coordinates[j][1];
                if ((xdiff==0 && dx!=0) || (dx==0 && xdiff!=0)) return false;
                if (xdiff==0 && xdiff==dx) continue;
                double grad1=(double)dy/dx, grad2=(double)ydiff/xdiff;
                if (grad1!=grad2) return false;
            }
        }
        return true;
    }
};