class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> childToParent;
        childToParent[root]=NULL;
        map<TreeNode*,bool> visited;
        TreeNode* node;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            visited[front]=false;

            if(front->left){
                q.push(front->left);
                childToParent[front->left]=front;
            }
            if(front->right){
                q.push(front->right);
                childToParent[front->right]=front;
            }

            if(front->val==start){
                node=front;
            }
        }


        q.push(node);
        visited[node]=true;
        int time=0;


        while(!q.empty()){
            
            int size=q.size();
            int flag=0;
            while(size--){
                TreeNode* front=q.front();
                q.pop();

                if(front->left && !visited[front->left]){
                    q.push(front->left);
                    visited[front->left]=true;
                    flag=1;
                }
                if(front->right && !visited[front->right]){
                    q.push(front->right);
                    visited[front->right]=true;
                    flag=1;
                }

                if(childToParent[front]!=NULL && !visited[childToParent[front]]){
                    q.push(childToParent[front]);
                    visited[childToParent[front]]=true;
                    flag=1;
                }
            }
            if(flag)time++;

            


        }
        return time;


    }
};
