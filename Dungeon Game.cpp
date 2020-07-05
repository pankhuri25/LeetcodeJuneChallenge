class Solution {
public:
    
     int calculateMinimumHP(vector<vector<int>>& dungeon) 
     {
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        dp[m][n-1] = 1;
        dp[m-1][n] = 1;
        
        for(int i = m - 1; i >= 0; --i)
        {
            for(int j = n - 1; j >= 0; --j)
            {
                dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]);
            }
        }
        return dp[0][0];
         
     }
    /*
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
     {
    
        if (dungeon.empty() || dungeon[0].empty()) 
            return 0;  // invalid
        int rows = dungeon.size();
        int cols = dungeon[0].size();
         
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
         
        for (int i=rows-1; i >= 0; --i) 
        {
            for (int j=cols-1; j >= 0; --j) 
            {
                if (i == rows - 1 && j == cols - 1) 
                {
                    dp[i][j] = min(0, dungeon[i][j]);
                }
                else if (i == rows - 1)
                {
                    dp[i][j] = min(0, dungeon[i][j] + dp[i][j+1]);
                }
                else if (j == cols - 1) 
                {
                    dp[i][j] = min(0, dungeon[i][j] + dp[i+1][j]);
                }
                else 
                {
                    dp[i][j] = min(0, dungeon[i][j] + max(dp[i][j+1], dp[i+1][j]));
                }
            }
        }
        return -dp[0][0] + 1;
     }
     */

    /*
    //My Approach (not working)
    void func(vector<vector<int>>& dungeon, int m, int n, int i, int j)
    {
        if(i<0 || i>=m || j<0 || j>=n)
            return;
        else if (i>0 && i+1<m && j>0 && j+1<n)
        {
            if(j+1==n)
            {
                dungeon[i+1][j] +=dungeon[i][j];
                func(dungeon, m, n, i+1, j);
            }
            if(i+1==m)
            {
                dungeon[i][j+1] +=dungeon[i][j];
                func(dungeon, m, n, i, j+1);
            }
            else if(dungeon[i][j+1] > dungeon[i+1][j])   //right
            {
                dungeon[i][j+1] +=dungeon[i][j];
                func(dungeon, m, n, i, j+1);
            }
            else if(dungeon[i][j+1] < dungeon[i+1][j] )                                  //down
            {
                dungeon[i+1][j] +=dungeon[i][j];
                func(dungeon, m, n, i+1, j);
            }     
        } 
        return;
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int m = dungeon.size();
        int n = dungeon[0].size();
        // vector<int> dirs = {{0,1}, {1,0}};
        
        func(dungeon, m, n, 0, 0);
        return 1 - dungeon[m-1][n-1];
    }
    
    */
};
