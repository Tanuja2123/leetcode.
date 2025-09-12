class Solution {
public:
//steps : if hl less move l then r, if
    int trap(vector<int>& height) {
        int ans=0; int l=0, r=height.size()-1;
        int lmax=0, rmax=0;
        while(l<r){
            if(height[l] <= height[r]){
                if(lmax >height[l]){
                    ans += lmax-height[l];
                } else{
                    lmax= height[l];
                }
                l++;
            } else { // rmax>lmax
                if(rmax > height[r]){
                    ans +=rmax-height[r];
                } else{
                    rmax= height[r];
                }
                r--;
            }
        }
        return ans;
        
    }
};