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
    vector<int> nextLargerNodes(ListNode* head) {

        if( head -> next == NULL){
            return {0};
        }

        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* curr = head;

        int count = 0;

        while(temp != NULL){
            temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
            count++;
        }

        ListNode* tempNew = prev;

        vector<int> ans(count,0);
        stack<int> st;

        //Now the new head is prev.
        tempNew = prev -> next;

        st.push(prev -> val);
        int counter = 1;

        

        while( tempNew != NULL){
             if( tempNew -> val < st.top() ){
                ans[counter] = st.top();
            }
            else if( tempNew -> val >= st.top()){
                while(st.size() > 0 && st.top() <= tempNew -> val){
                    st.pop();
                }
                if(st.size() > 0){
                    ans[counter] = st.top();
                }
            }
            counter++;
            st.push(tempNew -> val);
            tempNew = tempNew -> next;
        }
      
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
