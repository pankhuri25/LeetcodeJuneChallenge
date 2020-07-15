class Solution {
public:

    int numSquares(int n)
    {
        if(dp[n]!=-1)
            return dp[n];
        if(n==0)
            return dp[n]=0;

        int ans=INT_MAX;
        
        for(int i=1; i*i<=n; i++)
        {
            ans=min(ans, 1+ numSquares(n-i*i));
        }
        return dp[n]=ans;
    } 
};
