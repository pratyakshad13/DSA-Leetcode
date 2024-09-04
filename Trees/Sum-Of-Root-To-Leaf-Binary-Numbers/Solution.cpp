class Solution {
    void getAllNumbers(TreeNode* root,vector<string>& nums,string temp){
        if( root ->left == NULL && root->right == NULL){
            temp += to_string(root->val);
            nums.push_back(temp);
            return;
        }
        temp += to_string( root ->val);
        if(root->left) getAllNumbers(root->left,nums,temp);
        if(root->right)getAllNumbers(root->right,nums,temp);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        vector<string> nums;
        getAllNumbers(root,nums,"");

        int sum = 0;

        for( auto ele : nums){
            cout<<ele<<" ";
            int temp = 0, k = 0;
            for( int i = ele.size() - 1 ; i>= 0 ; i--){
                temp = temp + (ele[i]- 48)*pow(2,k);
                k++;
            }
            sum += temp;
        }

        return sum;
    }
};
