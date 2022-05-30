class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1=="0") return num2;
        else if (num2=="0") return num1;
        int carry=0;
        string ans="";
        int i=num1.length()-1;
        int j=num2.length()-1;
        while (i>=0 || j>=0 || carry) {
            if (i>=0) {
                carry+=num1[i--]-'0';
            }
            if (j>=0) {
                carry+=num2[j--]-'0';
            }
            ans += char(carry%10 + '0');
            carry /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};