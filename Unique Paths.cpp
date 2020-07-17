class Solution {
public:
    
    //Approach DP soln
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n ;j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j]  = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
    /*
    //Approach 2 (Space Optimized)
     int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        dp[0][1]=1;
        int  i,j;
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m][n];  
     }
    */
    /*
    DFS Approach giving TLE
    int dfs(vector<vector<int>> maze, int m, int n, int i, int j)
    {
        if(i==n-1 && j==m-1)
            return 1;
        if(i>n-1 || j>m-1)
            return 0;
        
        int x = dfs(maze,m,n,i+1,j);
        int y = dfs(maze,m,n,i,j+1);
        
        return x+y;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> maze (n,vector<int> (m));
        return dfs(maze,m,n,0,0);
    }
    */
};
