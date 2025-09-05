class Solution {
public:
     string licenseKeyFormatting(string s, int k) {
        string cleaned;
        for (char c : s) {
            if (c != '-') {
                cleaned.push_back(toupper(c));
            }
        }

        int n = cleaned.size();
        int first_group = n % k == 0 ? k : n % k;

        string res = cleaned.substr(0, first_group);
        for (int i = first_group; i < n; i += k) {
            res += "-" + cleaned.substr(i, k);
        }

        return res;
    }
};