class Solution {
public:
    vector<string>res;
    unordered_set<string>st;
    void solve(string &s, int idx, string curr){
        if(idx>=s.length()){
            res.push_back(curr);
            return;
        }
        for(int j=idx; j<s.length(); j++){
            string temp= s.substr(idx, j-idx+1); //substr -- start, length

            if(st.find(temp) != st.end()){
                //backtracking
                string temp2= curr;
                if(!curr.empty()){
                    curr+=" ";
                }
                curr +=temp; //crucial step
                solve(s, j+1, curr);
                curr=temp2;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto w:wordDict){
            st.insert(w);
        }
        string curr="";
        solve(s, 0, curr);
        return res;
    }
};