class Solution {
private:
    struct TrieTree {
        string word;
        TrieTree *children[26];
        TrieTree() : word("") {memset(children, 0x0, sizeof(children));}
    };

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieTree* root = new TrieTree();
        for (auto w : words) {
            TrieTree *node = root;
            for (auto ch : w) {
                if (node->children[ch-'a'] == NULL) node->children[ch-'a'] = new TrieTree();
                node = node->children[ch-'a'];
            }
            node->word = w;
        }
        
        vector<string> result;
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                dfs(board, i, j, root, result);
            }
        }
        return result;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieTree* root, vector<string>& result) {
        if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]=='#') return;
        TrieTree* node = root;
        if (node->children[board[i][j]-'a'] == NULL) return;
        node = node->children[board[i][j]-'a'];
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = "";
        }
        char ch = board[i][j];
        board[i][j] = '#';
        dfs(board, i-1, j, node, result);
        dfs(board, i+1, j, node, result);
        dfs(board, i, j-1, node, result);
        dfs(board, i, j+1, node, result);
        board[i][j] = ch;
    }
};
