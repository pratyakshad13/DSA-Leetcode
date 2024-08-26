class Solution {
public:
    void postOrder(Node* root,vector<int>* res){
        for(int i=0;i<root->children.size();i++){
            postOrder(root->children[i],res);
        }
        res->push_back(root->val);

    }
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(root==NULL || root->children.size()==0){
            if(root!=NULL && root->children.size()==0) res.push_back(root->val);
            return res;
        } 
        
        postOrder(root,&res);
        return res;
        
    }
};
