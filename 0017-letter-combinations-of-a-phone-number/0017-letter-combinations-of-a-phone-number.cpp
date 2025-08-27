class Solution {
public:
    vector<string>res;
    int n;
    void solve( string &digits,string temp, unordered_map<char, string>&mp, int id ){
       if(temp.length()==n){
        res.push_back(temp);
        return;
       }
       char ch=digits[id];
       string str= mp[ch];
       for(int i=0; i<str.size(); i++){
        temp.push_back(str[i]);
        solve(digits, temp, mp, id+1);
        temp.pop_back();
       }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0){
            return {};
        }
        n=digits.size();
        string temp="";
        unordered_map<char, string>mp;
        mp['2']="abc";
        mp['3']= "def";
        mp['4']= "ghi";
        mp['5']= "jkl";
        mp['6']= "mno";
        mp['7']= "pqrs";
        mp['8']= "tuv";
        mp['9']= "wxyz";
        solve(digits, temp, mp, 0);
        return res;

    }
};