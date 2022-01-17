class Solution {
public:
    void splitString(string s, vector<string> &v){
	
        string temp = "";
        for(int i=0;i<s.length();++i){

            if(s[i]==' '){
                v.push_back(temp);
                temp = "";
            }
            else{
                temp.push_back(s[i]);
            }

        }
        v.push_back(temp);

    }
    
    bool wordPattern(string pattern, string s) {
        int n = pattern.length();
        vector<string> arr;
        splitString(s, arr);
        int l = arr.size();
        if (n != l) return false;
        map<char, string> map1;
        map<string, char> map2;
        for (int i=0;i<n;i++) {
            if (map1.count(pattern[i]) == 0) map1[pattern[i]] = arr[i];
            else if (map1[pattern[i]] != arr[i]) return false;
            if (map2.count(arr[i]) == 0) map2[arr[i]] = pattern[i];
            else if (map2[arr[i]] != pattern[i]) return false;
        }
        return true;
    }
};