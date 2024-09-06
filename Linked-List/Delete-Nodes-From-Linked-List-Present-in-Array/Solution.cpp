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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st;
        for( int i : nums){
            st.insert(i);
        }

        ListNode* temp = head;

        while(st.count(temp -> val) > 0){
            temp = temp -> next;
        }

        head = temp;

        while( temp != NULL){
            if( temp->next != NULL && st.count(temp -> next -> val) > 0 ){
                temp ->next = temp ->next->next;
            }
            else{
                temp = temp ->next;
            }
        }
        return head;

        
    }
};
