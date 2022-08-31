class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stek;
        string ans;
        
        for(int i=0;  i<path.length(); i++) {
            if(path[i] == '/')    
                continue;
            string temp;
            while(i < path.length() && path[i] != '/') {
                temp += path[i];
                i++;
            }
            if(temp == ".")
                continue;
            else if(temp == "..") {
                if(!stek.empty()) stek.pop();
            }
            else
                stek.push(temp);
        }
        while(!stek.empty()) {
            ans = "/" + stek.top() + ans;
            stek.pop();
        }
        
        return ans.length() == 0 ? "/" : ans;
    }
};