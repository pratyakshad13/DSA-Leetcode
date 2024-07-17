class Solution {
public: 
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL) return NULL;

        TreeNode* newNode=new TreeNode();

        if(root1 && root2){
            newNode->val=root1->val+root2->val;
            
        }

        if(root1==NULL){
            newNode->val=root2->val;
            newNode->left=mergeTrees(NULL,root2->left);
            newNode->right=mergeTrees(NULL,root2->right);
            return newNode;
             
        }
        if(root2==NULL){
            newNode->val=root1->val;
            
            newNode->left=mergeTrees(root1->left,NULL);
            newNode->right=mergeTrees(root1->right,NULL);
            return newNode;
        }

        newNode->left=mergeTrees(root1->left,root2->left);
        newNode->right=mergeTrees(root1->right,root2->right);

        return newNode;
    }
};
