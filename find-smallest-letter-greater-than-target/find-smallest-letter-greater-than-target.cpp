class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l=0, r=letters.size()-1;
        while (l<=r) {
            int mid=l+(r-l)/2;
            if (letters[mid]<=target) l=mid+1;
            else r=mid-1;
        }
        if (l>=letters.size() || letters[l]<=target) return letters[0];
        return letters[l];
    }
};