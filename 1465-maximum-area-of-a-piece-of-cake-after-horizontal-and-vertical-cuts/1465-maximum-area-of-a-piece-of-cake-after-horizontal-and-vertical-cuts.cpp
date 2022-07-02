class Solution {    
public:
    int maxArea(int h, int w, vector<int>& hs, vector<int>& vs) {
        sort(hs.begin(),hs.end());
        sort(vs.begin(),vs.end());
        hs.insert(hs.begin(),0); hs.push_back(h);
        vs.insert(vs.begin(),0); vs.push_back(w);
        int maxH=0;
        int maxW=0;
        for (int i=0; i<hs.size()-1; i++) maxH=max(hs[i+1]-hs[i],maxH);
        for (int j=0; j<vs.size()-1; j++) maxW=max(vs[j+1]-vs[j],maxW);
        long long H = (long long) maxH;
        long long W = (long long) maxW;
        return (int) ((H*W) % 1000000007);
    }
};