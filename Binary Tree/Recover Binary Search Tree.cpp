void recoverTree(TreeNode* root) {
        stack<TreeNode*>s;
        TreeNode*curr=root , *prev =NULL;
        TreeNode*first=NULL ,*second=NULL,*mid=NULL;
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
              if(first==NULL)
              {
                  first=prev;
                  mid=curr;
              }
              
              else
                  second=curr;
             }
            prev =curr;
            curr = curr->right;
                
        }
        if(second==NULL)
        swap(first->val , mid->val);
        else
        swap(first->val , second->val);
        return;
    }
