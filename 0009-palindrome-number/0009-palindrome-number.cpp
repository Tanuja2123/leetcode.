class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || x %10 ==0 && x !=0) return false; // negative, x multiple of x
        int reversed= 0;
        while(x> reversed){
            reversed= reversed*10 + x%10;
            x = x/10;
        } // in the end rever>x or equal
        return x== reversed || x== reversed/10;
    }
};