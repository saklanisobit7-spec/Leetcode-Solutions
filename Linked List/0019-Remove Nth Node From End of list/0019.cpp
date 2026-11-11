class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp=head;
        int c=0;
        int pos;
        while(temp!=NULL)
        {
            c++;
            temp = temp->next;
        }
        pos = c-n+1;
        temp=head;
        if (pos==1)
        {
            head = head->next;
            delete temp;
            return head;
        }
      
        for (int i=1;i<pos-1;i++)
        {
            temp = temp->next;
        }
        ListNode *del = temp->next;
        temp->next = del->next;
        delete del;

        return head;
    }
 
};