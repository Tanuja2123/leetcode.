class Solution {
public:
    int reverseBits(int n) {
        uint32_t res= 0;
        for(int i=0; i<32; i++){
            res <<=1; //right shift -> building step by step
            res |= (n&1); // extracting the right most digit from the n
            n>>=1; //left shift
        }
        return res;
    }
};