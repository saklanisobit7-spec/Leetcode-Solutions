class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *temp=head;
        int pos;
        int c=0;
        while(temp!=NULL)
        {
            c++;
            temp=temp->next;
        }
        pos = (c/2)+1;
        temp=head;
        for (int i=1;i<pos;i++)
        {
            temp=temp->next;
        }
        return temp;
    }
};