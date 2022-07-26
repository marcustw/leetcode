class Solution {
    void recurse(vector<vector<int>>& image, int x, int y, int color, int cur) {
        if (x<0 || y<0 || x>=image.size() || y>=image[0].size() || image[x][y]!=cur) return;
        image[x][y]=color;
        recurse(image,x+1,y,color,cur);
        recurse(image,x-1,y,color,cur);
        recurse(image,x,y+1,color,cur);
        recurse(image,x,y-1,color,cur);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int cur=image[sr][sc];
        if (color!=cur)
            recurse(image,sr,sc,color,cur);
        return image;
    }
};