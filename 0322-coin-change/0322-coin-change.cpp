class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>dp(amount+1, 1e9);
        // intialization: base case
        dp[0]=0;
        for(int i=1; i<=amount; i++){ // start from 1
            for(int j=0; j<coins.size(); j++){
                if(coins[j]<=i){
                    dp[i]= min(dp[i], dp[i-coins[j]]+1); //1 coin added, 
                }
            }
        }
        return dp[amount]==1e9?-1:dp[amount];
    }
};