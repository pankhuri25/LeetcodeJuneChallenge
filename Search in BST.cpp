class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        /*
        if(root==NULL)
            return root;
        
        if(val < root->val)
            return searchBST(root->left,val);

        else if(val==root->val)
            return root;
        
        else
            return searchBST(root->right,val);
        */
        
        if(!root||root->val==val)
            return root;

        while(root)
        {
            if(val==root->val)
                return root;
            else if(val<root->val)
                root=root->left;
            else 
                root=root->right;
        }
        return NULL;
    }
};
