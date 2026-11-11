class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *current,*prev,*nextnode;
        prev = NULL;
        current = head;
        while(current!=NULL)
        {
            nextnode = current->next;
            current->next=prev;
            prev=current;
            current=nextnode;
        }
        return prev;
    }
    
};