class Solution {
public:
    bool isPalindrome(ListNode* head) {

        if( head == NULL || head ->next == NULL){
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        ListNode* prev = NULL;
        ListNode* temp = NULL;
        ListNode* curr = NULL;
        ListNode* currPrev = NULL;

        while(fast != nullptr && fast -> next != nullptr){
            currPrev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        prev = NULL;
        curr = slow;
        temp = slow;
        while(curr != NULL){
            temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        currPrev -> next = NULL;

        ListNode* temp2 = prev;
        temp = head;

        while(temp != NULL && temp2 != NULL){
            if(temp -> val != temp2 -> val){
                return false;
            }

            temp = temp -> next;
            temp2 = temp2 -> next;
        }

        return true;
    }
};
