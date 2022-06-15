class Solution {
public:
    int longestStrChain(vector<string>& words) {
        // sort the strings according to length
        sort(words.begin(),words.end(),[]
             (auto& a, auto& b) {
                 return a.length()>b.length();
             });
        
        // dp
        unordered_map<string,int> m;
        
        // initialise dp
        for (string word : words) m[word]=1;
        
        int ans=0;
        
        /*
        For each word in words
            form a string wordMinusCharC by removing a char C from word
            if wordMinusChar exists in map, a chain from 
                wordMinusCharC + C -> word
                find max length of chain that you can delete to form wordMinusCharC
        
            # Note that max length of chain that you can delete to form wordMinusCharC = max length of chain you can add from wordMinusCharC to form a word existing in words
                
        */
        for (auto& word : words) {
            for (int i=0; i<word.length(); i++) {
                string wordMinusCharC=word;
                wordMinusCharC.erase(i,1);
                m[wordMinusCharC]=max(m[wordMinusCharC],1+m[word]);
            }
            ans=max(m[word],ans);
        }
        return ans;
    }
};