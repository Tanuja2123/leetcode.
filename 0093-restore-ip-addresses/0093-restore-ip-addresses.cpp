class Solution {
public:
    vector<string>res;
    int n;
    void solve(string s, int id, int part, string curr){
         if(part==4){
            if(id==n){
                curr.pop_back();
                res.push_back(curr);
            }
            return;
        }
        for(int len=1; len<=3; len++){
            if(id+len >n) break;

            string seg= s.substr(id, len);
            int val=stoi(seg);
            if(seg[0]=='0' && len>1 || val>255) continue;
            solve(s, id+len, part+1, curr+seg+'.');
        }
    }
    vector<string> restoreIpAddresses(string s) {
        n=s.length();
        solve(s, 0, 0, "");
        return res;
       
    }
};