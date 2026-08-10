class Solution {
public:
    int findP( int l, int r, vector<int>& nums, int target){
        int mid;
        while (l<r){
            mid= l+(r-l)/2;
            if(nums[mid]>nums[r]){
                l=mid+1;
            } else{
                r=mid;
            }
        }
        return l;
    }
    int bs(int l, int r, vector<int>& nums, int target){
        int mid;
        while(l<=r){
            mid= l+(r-l)/2;
            if(nums[mid]<target){
                l=mid+1;
            } else if(nums[mid]>target){
                r=mid-1;
            } else{
                return mid;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int r= nums.size()-1, l=0;
        
        int pivot = findP(l, r, nums, target);
        int idx= bs(l, pivot-1, nums, target);
        if( idx != -1){
            return idx;
        }
        idx= bs(pivot, r, nums, target);
        return idx;
    }
};