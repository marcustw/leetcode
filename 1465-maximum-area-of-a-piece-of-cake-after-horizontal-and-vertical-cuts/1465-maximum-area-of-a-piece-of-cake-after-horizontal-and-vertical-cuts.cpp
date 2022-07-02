class Solution {
    long long ans=0;
    long long const mod=1000000007;
    
    long long moduloMultiplication(long long a, long long b, long long mod) {
        long long res = 0; 
        a %= mod;
        while (b) {
            if (b & 1)
                res = (res + a) % mod;
            a = (2 * a) % mod;
            b >>= 1;
        }
        return res;
    }
public:
    int maxArea(int h, int w, vector<int>& hs, vector<int>& vs) {
        sort(hs.begin(),hs.end());
        sort(vs.begin(),vs.end());
        hs.insert(hs.begin(),0);
        vs.insert(vs.begin(),0);
        hs.push_back(h);
        vs.push_back(w);
        long long maxH=0;
        long long maxW=0;
        for (int i=0; i<hs.size()-1; i++) {
            long long l=hs[i+1]-hs[i];
            maxH=max(l,maxH);
        }
        for (int j=0; j<vs.size()-1; j++) {
            long long b=vs[j+1]-vs[j];
            maxW=max(b,maxW);
        }
        
        return (int) moduloMultiplication(maxH,maxW,mod);
    }
};