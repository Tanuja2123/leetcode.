class Solution {
public:
    vector<vector<string>>res;
    bool pali(string s){
        int l=0, r=s.length()-1;
        while(l<r){
            if(s[l]==s[r]){
                l++; r--;
            } else{
                return false;
            }
        }
        return true;
    }
    void dfs(string s, int id, vector<string>temp){
        if(id==s.length()){
            res.push_back(temp);
            return;
        }
        for(int i=id; i<s.length(); i++){
            string str= s.substr(id, i-id+1);
            if(pali(str)){
                temp.push_back(str);
                dfs(s, i+1 ,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        int id=0;
        dfs(s, id, temp);
        return res;
    }
};