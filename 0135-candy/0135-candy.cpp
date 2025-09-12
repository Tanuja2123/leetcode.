class Solution {
public:
    int candy(vector<int>& arr) {
        vector<int>c(arr.size(), 1);
        for(int i=1; i<arr.size(); i++){
            if(arr[i]> arr[i-1]){
                c[i] =c[i-1]+ 1;
            }
        }
        for(int i=arr.size()-2; i>=0; i--){
            if(arr[i]>arr[i+1]){
                c[i] = max(c[i], c[i+1] + 1);
            }
        }
        int ans=0;
        for(int i: c){
            ans+= i;
        }
        return ans;
    }
};