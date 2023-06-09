class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo=0, hi=letters.size()-1;
        while (lo<=hi) {
            int m = lo+(hi-lo)/2;
            if (letters[m]<=target) lo=m+1;
            else hi=m-1;
        }
        return lo>=letters.size() ? letters[0] : letters[lo];
    }
};