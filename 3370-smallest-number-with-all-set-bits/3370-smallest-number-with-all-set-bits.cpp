class Solution {
public:
    bool isallbitset(int x){
        return (x & (x+1))==0;
    }
    int smallestNumber(int n) {
        int res=n;
        while(!isallbitset(res)){
            res++;
        }
        return res;
    }
};