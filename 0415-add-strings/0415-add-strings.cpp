class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        if (num1.length() > num2.length()) {
            swap(num1, num2);
        }
        
        int l1 = num1.length();
        int l2 = num2.length();
        string ans = "";
        
        int carry = 0;
        for (int i=0; i<l1; i++) {
            int sum = carry + num1[i]-'0' + num2[i]-'0';
            ans += to_string(sum%10);
            carry = sum/10;
        }
        
        for (int i=l1; i< l2; i++) {
            int sum = carry + num2[i]-'0';
            ans += to_string(sum%10);
            carry = sum/10;
        }
        
        if (carry == 1) {
            ans+= to_string(carry);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};