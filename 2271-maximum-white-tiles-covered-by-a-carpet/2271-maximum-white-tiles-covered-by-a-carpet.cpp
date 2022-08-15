class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());
        int ans=0;
        int l=0, r=0, cover=0;
        while (ans<carpetLen && r<tiles.size()) {
            if (tiles[l][0]+carpetLen>tiles[r][1]) {
                cover += tiles[r][1] - tiles[r][0] + 1;
                ans = max(ans, cover);
                r++;
            } else {
                int cover2 = max(0, tiles[l][0] + carpetLen - tiles[r][0]);
                ans = max(ans, cover + cover2);
                cover -= (tiles[l][1] - tiles[l][0] + 1);
                l++;
            }
        }
        return ans;
    }
};