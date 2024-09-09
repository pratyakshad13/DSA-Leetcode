/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));

        int rowStart = 0,rowEnd = m - 1  , colStart = 0 ,colEnd = n -1 ;
        bool isEmpty = false;

        while( rowStart <= rowEnd && colStart <= colEnd && head != NULL){

            for( int col = colStart ; col <= colEnd ; col++){
                if( head != NULL){
                    ans[rowStart][col] = head ->val;
                    head = head ->next;
                }
                else{
                    isEmpty = true;
                    break;
                }
            }

            rowStart++;

            for( int row = rowStart ; row <= rowEnd ; row++){
                if( head != NULL){
                    ans[row][colEnd] = head ->val;
                    head = head ->next;
                }
                else{
                    isEmpty = true;
                    break;
                }
            }
            colEnd--;


            for( int col = colEnd ; col >= colStart ; col--){
                if( head != NULL){
                    ans[rowEnd][col] = head ->val;
                    head = head ->next;
                }
                else{
                    isEmpty = true;
                    break;
                }
            }
            rowEnd--;


            for( int row = rowEnd ; row >= rowStart ; row--){
                if( head != NULL){
                    ans[row][colStart] = head ->val;
                    head = head ->next;
                }
                else{
                    isEmpty = true;
                    break;
                }
            }
            colStart++;

            if( isEmpty){
                break;
            }

        }

        return ans;
    }
};
