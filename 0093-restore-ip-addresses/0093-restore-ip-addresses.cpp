class Solution {
public:
    int n;
    vector<string> res;
    void find(string& s, int id, int part, string curr) {
        if (part == 4) {
            if (id == n) {
                curr.pop_back();
                res.push_back(curr);
            }
            return;
        }
        for (int len = 1; len <= 3; len++) { // 3 len max possible
            if (id + len > n)
                break;
            string segment = s.substr(id, len); // substr of len staring form id
            int val = stoi(segment);
            if (segment[0] == '0' && len>1 || val > 255) // len greater than 1
                continue;
            find(s, id + len, part + 1, curr + segment + ".");
        }
    }
    vector<string> restoreIpAddresses(string s) {
        n = s.length();
        find(s, 0, 0, ""); // string s, id, parts, curr
        return res;
    }
};