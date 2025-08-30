class Solution {
public:
    // building 
    using ll=long long ;
    vector<string>res;
    string num; int target;
    void backtrack(int id, ll eval, ll multed, string path){
        if(id==num.length()){
            if(eval==target) {
                res.push_back(path);
            }
            return;
        }
        for(int i=id; i<num.length(); i++){
            if(i>id && num[id]=='0') break; // any longer substring with this will also start from the 0
            string temp = num.substr(id, i-id+1);
            ll tempnum= stoll(temp);
            if(id==0 ){
                backtrack(i+1, tempnum, tempnum, temp);
            } else{
                backtrack(i+1, eval+ tempnum, tempnum, path+ "+" + temp);
                backtrack(i+1, eval- tempnum, -tempnum, path+ "-" + temp);
                backtrack(i+1, eval-multed + multed * tempnum, multed*tempnum, path+ "*" + temp);

            }
        }
    }
    vector<string> addOperators(string num, int target) {
        this->num=num; // this used for class
        this->target=target; //this used for class solution
        backtrack(0, 0, 0, ""); //id, eval, multed, path
        return res;
    }
};