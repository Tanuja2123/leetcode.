class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        while(n){
            count += (n & 1);
            n>>=1; //left shift to get/ check digit from left to right 
        }
        return count;
    }
};