bool isValidBST(TreeNode* root) 
{
        stack<TreeNode*>s;
        TreeNode*curr=root , *prev =NULL;
        while(!s.empty() || curr)
        {
            while(curr)
            {
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            s.pop();
            if(prev  && curr->val <= prev->val)
            {
              return 0;
            }
            prev =curr;
            curr = curr->right;
                
        }
        return 1;
}
