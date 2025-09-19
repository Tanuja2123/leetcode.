class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() <= 2)  
            return points.size();

        int n = points.size();
        int res = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<string, int> mp;
            int duplicates = 1;
            int currmax = 0;

            for (int j = i+1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    duplicates++;
                    continue;
                }

                if (dx == 0) {
                    // vertical line
                    mp["vert"]++;
                    currmax = max(currmax, mp["vert"]);
                } 
                else if (dy == 0) {
                    // horizontal line
                    mp["horiz"]++;
                    currmax = max(currmax, mp["horiz"]);
                } 
                else {
                    int g = gcd(dx, dy);
                    dx /= g;
                    dy /= g;

                    if (dx < 0) {
                        dx = -dx;
                        dy = -dy;
                    }

                    string slope = to_string(dy) + "/" + to_string(dx);
                    mp[slope]++;
                    currmax = max(currmax, mp[slope]);
                }
            }
            
            res = max(res, currmax + duplicates);  // ✅ this must be outside inner loop
        }
        
        return res;
    }
};

