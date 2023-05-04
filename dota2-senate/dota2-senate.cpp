class Solution {
public:
    string predictPartyVictory(string senate) {
        int n=senate.size();
        queue<int> r, d;
        for (int i=0; i<n; i++) {
            if (senate[i]=='D') d.push(i);
            else r.push(i);
        }
        // Trick is A...B...., A can ban B for ALL the following rounds
        while (!r.empty() && !d.empty()) {
            int rIdx=r.front(), dIdx=d.front();
            r.pop();
            d.pop();
            if (rIdx<dIdx) r.push(rIdx+n);
            else d.push(dIdx+n);
        }
        // game will last till all the DIRE or all the RADIANT has no rights
        return r.size()<d.size() ? "Dire" : "Radiant";
    }
};