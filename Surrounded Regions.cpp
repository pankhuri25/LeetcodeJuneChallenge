class Solution {
public:
    
    void dfs(vector<vector<char>>& board, int i, int j, vector<vector<int>> dirs)
    {
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]=='#')
            return;
        if(board[i][j]=='X')
            return;
        
        board[i][j]='#';
        
        for(auto dir: dirs)
        {
            dfs(board,i + dir[0],j + dir[1], dirs);
        }
        return;  
    }
    void solve(vector<vector<char>>& board) {
    
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        if(board.size()==0)
            return;
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<int>> dirs = {{-1,0}, {0,-1}, {1,0}, {0,1}};
        for(int i=0; i<m; i++)
        {
            if (board[i][0]=='O')
                dfs(board, i, 0, dirs);
            
            if (board[i][n-1]=='O')
                dfs(board,i,n-1, dirs);
        }
        
        for(int j=0; j<n; j++)
        {
            if(board[0][j]=='O')
                dfs(board, 0, j, dirs);
            
            if(board[m-1][j]=='O')
                dfs(board, m-1, j, dirs);
        }
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='#')
                    board[i][j]='O';
            }
        }
    }
};
