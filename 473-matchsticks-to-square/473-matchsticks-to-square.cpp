class Solution {
    bool recurse(const vector<int> &matches, vector<int> &square, int index, const int k) {
        if (index==matches.size())
            return square[0]==square[1] && square[1]==square[2] && square[2]==square[3];
        for (int i=0; i<4; i++) {
            if (square[i]+matches[index]> k) continue;
            int j=i;
            while (--j>=0) // third
                if (square[i]==square[j]) break;
            if (j!=-1) continue;
            square[i]+=matches[index];
            if (recurse(matches, square, index+1, k))
                return true;
            square[i]-=matches[index];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int k=accumulate(matchsticks.begin(), matchsticks.end(), 0); //O(n) to find perimeter
        if (k%4!=0) return false;
        k/=4; //square length has to be k
        sort(matchsticks.begin(), matchsticks.end(), [](const int &l, const int &r){return l > r;}); //O(n logn)
        vector<int> square(4);
        return recurse(matchsticks, square, 0, k);
    }
};