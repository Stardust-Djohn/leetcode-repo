class MyLinkedList {
public:
    MyLinkedList() {
        head = new ListNode(0);
        len = 0;
    }
    
    int get(int index) {
        if (index >= len || index < 0) {
            return -1;
        }
        ListNode* cur = head->next;
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode* tmp = new ListNode(val); 
        tmp->next = head->next;
        head->next = tmp;
        len++;
    }
    
    void addAtTail(int val) {
        ListNode* tmp = new ListNode(val);
        ListNode* cur  = head;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = tmp;
        len++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > len) return;
        ListNode* tmp = new ListNode(val);
        ListNode* cur = head;
        while(index--) {
            cur = cur->next;
        }
        tmp->next = cur->next;
        cur->next = tmp;
        len++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= 0 && index <len) {
            ListNode* cur = head;
            while(index--) {
                cur = cur->next;
            }
            ListNode* tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;

            len--;
        }
        else return;
    }
private:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };
    ListNode* head;
    int len;
    
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