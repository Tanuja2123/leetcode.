class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int l= digits.size()-1;
        if(digits[l] < 9){
            digits[l]++;
            return digits;
        } else{
            digits[l]=0;
            for(int i=l-1; i>=0; i--){
                if(digits[i]<9){
                    digits[i]++;
                    return digits;
                }
                digits[i]=0;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};