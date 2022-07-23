class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> arr(26);
        int ans=0;
        for (int i=0; i<s.length(); i++) {
            arr[s[i]-'a'].push_back(i);
        }
        
        for (auto& word : words) {
            int x=-1;
            bool found=true;
			for (char c : word) {
                int j=c-'a';
                int lo=0;
                int hi=arr[j].size()-1;
                while (lo<=hi) {
                    int mid=lo+(hi-lo)/2;
                    if (arr[j][mid]<=x) lo=mid+1;
                    else hi=mid-1;
                }
				if (arr[j].size()==0 || lo>=arr[j].size()) {
                    found = false;
                    break;
                } else {
                    x = arr[j][lo];
                }
			}
            if (found) ans++;
        }
            
        return ans;
    }
};