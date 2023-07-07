class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int lo1=0, lo2=0, k1=k, k2=k, n=answerKey.length(), i=0;
        for (i=0; i<n; ++i) {
            if (answerKey[i]=='T') k1--;
            else k2--;
            if (k1<0 && answerKey[lo1++]=='T') k1++;
            if (k2<0 && answerKey[lo2++]=='F') k2++;
        }
        return max(i-lo1, i-lo2);
    }
};