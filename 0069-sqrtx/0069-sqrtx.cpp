class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x;
        long long l=1, r=x/2;
        long long ans;
        long long mid;
        while(l<=r){
            mid= (r-l)/2+ l;
            long long sq= mid*mid;
            if(x== sq) return (int) mid;
            if(x< sq){
                r=mid-1;
            }
            if(x>sq){
                ans=mid;
                l=mid+1;

            }
        }
        return (int) ans;
    }
};