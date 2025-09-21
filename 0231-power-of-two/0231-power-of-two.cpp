class Solution {
public:
    // power of two has only 1 one and n-1 has all other 1 exept the one in the n
    bool isPowerOfTwo(int n) {
        if(n>0 && (n&(n-1))==0){
            return true;
        }
        return false;
    }
};