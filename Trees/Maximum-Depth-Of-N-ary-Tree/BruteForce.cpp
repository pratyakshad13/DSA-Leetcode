/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void maxDepth(Node* root,int currDepth,int& depth) {
        if(root -> children.size() == 0){
            // cout<<"This is the end node"<<root->val<<endl;
            depth = max(depth,currDepth + 1);
            return;
        }

        for(int i = 0 ; i < root->children.size() ; i++){
            // cout<<"called for :"<<root->children[i]->val<<endl;
            maxDepth(root->children[i],currDepth + 1 ,depth);
        }

    }

    int maxDepth(Node* root){
        if(root == NULL){
            return 0;
        }
        int ans = 0;
        maxDepth(root,0,ans);
        return ans;
    }
};
