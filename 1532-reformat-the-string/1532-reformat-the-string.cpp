class Solution {
public:
    string reformat(string s) {
        string digits, letters;
        string res;
        for(char c: s){
            if(isdigit(c)) digits.push_back(c);
            else letters.push_back(c);
        }
        string longer= (digits.size() <= letters.size())? letters: digits;
        string smaller= (digits.size() <= letters.size())?digits: letters;
        if(abs((int)longer.size() -(int) smaller.size()) > 1){
            return "";
        }
        for(int i=0; i<longer.size(); i++){
            res += longer[i];
            if(i<smaller.size()){
                res += smaller[i];
            }
        }
        return res;
    }

};