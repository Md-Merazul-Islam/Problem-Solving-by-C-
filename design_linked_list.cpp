class MyLinkedList {
public:
    ListNode* head;
    int size;
 
 
    int get(int index) {
        if (index < 0 || index >= size)
        {
            return -1;
        }
       ListNode * tmp = head;
       for (int i=0; i<index ;i++)
       {
           tmp = tmp->next;
       }
       return tmp->val;
    }
 
    void addAtHead(int val) {
        size++;
        ListNode * newnode = new ListNode (val);
        newnode->next = head;
        head = newnode;
    }
 
    void addAtTail(int val) {
        size++;
        ListNode * newnode = new ListNode (val);
        if(head== NULL) 
        {
            head= newnode;
            return;
        }
 
         ListNode * tmp = head;
         while(tmp!= NULL && tmp->next!= NULL)
         {
             tmp= tmp->next;
         }
         tmp->next = newnode;
 
    }
 
    void addAtIndex(int index, int val) {
 
        if(index <0 || index >size)
        {
            return;
        }
        size++;
        if(index==0)
        {
             addAtHead(val);
             return;
        }
          if(index==size)
        {
            addAtTail( val);
            return;
        }
        ListNode * newnode = new ListNode (val);
        ListNode * tmp= head ;
        for (int i=0;i<index-1;i++)
        {
            tmp = tmp->next;
        }
        newnode->next = tmp->next;
        tmp->next = newnode;
    }
 
 
    void deleteAtIndex(int index) {
    if (index < 0 || index >= size) {
        return;
    }
    
    size--;
    
    ListNode* tmp = head;
    
    if (index == 0) {
        head = tmp->next;
        delete tmp;
        return;
    }

    for (int i = 0; i < index - 1; i++) {
        tmp = tmp->next;
    }
    
    ListNode* deleteNode = tmp->next;
    
    if (tmp->next != NULL) {
        tmp->next = tmp->next->next;
    } else {
        tmp->next = NULL;
    }
    
    delete deleteNode;
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


























#include <iostream>

struct ListNode {
    int val;
    ListNode* prev;
    ListNode* next;

    ListNode(int value) : val(value), prev(nullptr), next(nullptr) {}
};

class MyLinkedList {
public:
    MyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        ListNode* tmp = head;
        for (int i = 0; i < index; i++) {
            tmp = tmp->next;
        }
        return tmp->val;
    }

    void addAtHead(int val) {
        ListNode* newnode = new ListNode(val);
        if (head == nullptr) {
            head = tail = newnode;
        } else {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        size++;
    }

    void addAtTail(int val) {
        ListNode* newnode = new ListNode(val);
        if (head == nullptr) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index > size || index < 0) {
            return;
        }
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == size) {
            addAtTail(val);
            return;
        }
        ListNode* newnode = new ListNode(val);
        ListNode* cur = head;
        for (int i = 0; i < index - 1; i++) {
            cur = cur->next;
        }
        newnode->next = cur->next;
        cur->next->prev = newnode;
        cur->next = newnode;
        newnode->prev = cur;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        size--;

        ListNode* tmp = head;

        if (index == 0) {
            head = tmp->next;
            if (head) {
                head->prev = nullptr;
            }
            delete tmp;
            return;
        }

        for (int i = 0; i < index - 1; i++) {
            tmp = tmp->next;
        }

        ListNode* deleteNode = tmp->next;
        tmp->next = deleteNode->next;
        if (tmp->next) {
            tmp->next->prev = tmp;
        } else {
            tail = tmp;
        }

        delete deleteNode;
    }

private:
    ListNode* head;
    ListNode* tail;
    int size;
};
