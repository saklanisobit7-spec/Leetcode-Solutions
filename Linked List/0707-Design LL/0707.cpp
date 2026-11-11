class Listnode{
public:
    int val;
    Listnode *next;
    Listnode(int x)
    {
        val = x;
        next = NULL;
    }
};
class MyLinkedList {
    Listnode *head;
    int size;
public:
    MyLinkedList() {
        head = new Listnode(0);
        size=0;
    }
    
    int get(int index) {
        if (index<0 || index>=size)
        {
            return -1;
        }
        Listnode *current = head->next;
        for (int i=0;i<index;i++)
        {
            current = current->next;
        }
        return current->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0,val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size,val);
    }
    
    void addAtIndex(int index, int val) {
        if (index<0 || index>size)
        {
            return;
        }
        Listnode *current = head;
        size++;
        for (int i=0;i<index;i++)
        {
            current=current->next;
        }
        Listnode *newnode = new Listnode(val);
        newnode->next=current->next;
        current->next=newnode;    
        }
    
    void deleteAtIndex(int index) {
        if (index<0 || index>=size)
        {
            return;
        }
        Listnode *current = head;
        for (int i=0;i<index;i++)
        {
            current = current->next;
        }
        size--;
        current->next=current->next->next;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */