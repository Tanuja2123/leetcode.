class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int j=0, i=0; 
        unordered_map<int,int>mp;
        int ans=0;
        while(j<n){
            mp[s[j]]++;
            while(mp[s[j]]>1){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            ans= max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};