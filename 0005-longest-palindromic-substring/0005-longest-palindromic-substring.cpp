class Solution {
public:
    int expand(string& s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            r++;
            l--;
        }
        return r - l - 1; // both moved i extra
    }
    string longestPalindrome(string s) {
        if (s.empty())
            return "";

        int start = 0;
        int maxlen = 0;
    
        for (int i = 0; i < s.size(); i++) {
            int oddl = expand(s, i, i);
            int evenl = expand(s, i, i + 1);

            int len = max(oddl, evenl);
            if (len > maxlen) {
                maxlen = len;
                start = i - (len - 1) / 2; // move len-1/2 back from center i to get to start
            }
        }
        return s.substr(start, maxlen); // CPP -start and then length
    }
};