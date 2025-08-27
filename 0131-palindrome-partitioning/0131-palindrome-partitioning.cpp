class Solution {
public:
vector<vector<string>>res;
int n;
bool ispali(string str){
    int l=0; int r=str.length()-1;
    while(l<r){
        if(str[l]==str[r]){
            l++; r--;
        } else{
            return false;
        }
    }
    return true;
    
}
void solve(string s, vector<string>&temp, int id){
    if(id >=n){
        res.push_back(temp);
        return;
    }
    for(int i=id; i<n; i++){
        if(ispali(s.substr(id, i-id+1))){ //start, len
            temp.push_back(s.substr(id, i-id+1));
            solve(s, temp, i+1);
            temp.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
        n=s.length();
        vector<string>temp;
        solve(s, temp, 0);
        return res;

    }
};