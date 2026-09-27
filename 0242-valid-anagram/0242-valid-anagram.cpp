class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int n= s.size();
        unordered_map<char, int>counts;
        unordered_map<char, int>countt;
        for(int i=0; i<n; i++){
            counts[s[i]]++;
            countt[t[i]]++;

        }
        if(counts==countt) return true;
        return false;

    }
};