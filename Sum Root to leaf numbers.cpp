class Solution {
public:
    
    int answer(TreeNode* root, int sum)
    {
        if(root==NULL)
            return 0;
        
        int summ = sum*10 + root->val;
        
        if(root->left==NULL && root->right==NULL)
            return summ;
        
        int x = answer(root->left, summ);
        int y = answer(root->right, summ);
        
        return x + y;
    }
    int sumNumbers(TreeNode* root) {
        return answer(root,0);
        
    }
};
