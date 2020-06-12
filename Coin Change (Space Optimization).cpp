int change(int amount, vector<int>& coins) {
         
         vector<int> dp(amount+1,0);  //size and values initialized with 0
         dp[0]=1;
         for(int i=0; i<coins.size(); i++)
         {
             for(int j=coins[i]; j<=amount; j++)
             {
                 dp[j] += dp[j-coins[i]];
             }
         }
         return dp[amount];
     }
    */
    //OR like this (almost same)
    
    int change(int amount, vector<int>& coins) {
         
    vector<int> dp(amount + 1);
        dp[0] = 1;
        for (const auto & c : coins) {
            for (int i = c; i <= amount; ++i) {
                dp[i] += dp[i - c];
            }
        }
        return dp[amount];
    }
