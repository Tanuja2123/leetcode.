class Solution {
public:
    unordered_set<string>used;
    void dfs(string s, int id, int currcount, int &maxcount){
        if(id==s.length()){
            maxcount= max(currcount, maxcount);
            return;
        }
        for(int i=id; i<s.length(); i++){
            string sub= s.substr(id, i-id+1);
            if(used.find(sub)==used.end()){
                used.insert(sub);
                dfs(s, i+1, currcount+1, maxcount);
                used.erase(sub);

            }
        }
    }
    int maxUniqueSplit(string s) {
        int id=0;
        int maxcount=0;
        dfs(s, id, 0, maxcount);
        return maxcount;
    }
};