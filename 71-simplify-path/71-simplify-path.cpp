class Solution {
public:
    string simplifyPath(string path) {
        string ans;
        stack<string> stek;
        for(int i=0;  i<path.length(); i++) {
            if (path[i] == '/')    
                continue;
            string temp;
            while(i < path.length() && path[i] != '/') {
                temp += path[i];
                i++;
            }
            if (temp == ".")
                continue;
            else if(temp == "..") {
                if(stek.size()) stek.pop();
            }
            else
                stek.push(temp);
        }
        while(stek.size()) {
            ans = "/" + stek.top() + ans;
            stek.pop();
        }
        
        return ans.length() == 0 ? "/" : ans;
    }
};