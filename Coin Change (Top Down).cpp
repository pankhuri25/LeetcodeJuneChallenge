int changeCoins(int amount, int i, vector<int>& coins, vector<vector<int>>& dp)
    {
        //base case
        if(amount==0)
            return 1;
        if(amount<0 || i==coins.size())
            return 0;
        if(dp[i][amount]!=-1)
            return dp[i][amount];
         
        return dp[i][amount] =changeCoins (amount, i+1, coins, dp) + changeCoins (amount-coins[i], i, coins, dp);
        
    }
    
    int change(int amount, vector<int>& coins) {
        
        vector<vector<int>> dp (coins.size() + 1, vector<int> (amount+1 , -1));
        return changeCoins(amount,0,coins,dp);
    }
