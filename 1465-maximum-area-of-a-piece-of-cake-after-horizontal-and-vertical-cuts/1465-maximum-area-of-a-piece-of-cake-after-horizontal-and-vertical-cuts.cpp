class Solution {    
public:
    int maxArea(int h, int w, vector<int>& hs, vector<int>& vs) {
        sort(hs.begin(),hs.end());
        sort(vs.begin(),vs.end());
        hs.push_back(h);
        vs.push_back(w);
        int maxH=hs[0];
        int maxW=vs[0];
        for (int i=0; i<hs.size()-1; i++) maxH=max(hs[i+1]-hs[i],maxH);
        for (int j=0; j<vs.size()-1; j++) maxW=max(vs[j+1]-vs[j],maxW);
        long long int H=(long long int)maxH;
        long long int W=(long long int)maxW;
        return (int) ((H*W) % 1000000007);
    }
};