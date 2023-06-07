class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        while (a>0 || b>0 || c>0) {
            int ba = a&1, bb = b&1, bc = c&1;

            if (bc==0) ans += (ba+bb);
            else if (ba==0 && bb==0) ans++;
            
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return ans;
    }
};