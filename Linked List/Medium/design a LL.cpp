class MyLinkedList {
public:

    struct Node{
        int val;
        Node* next;
        Node* prev;

        Node(int x){
            val = x;
            next = NULL;
            prev = NULL;
        }
    };

    Node* head;
    Node* tail;
    int size;

    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= size) return -1;

        Node* curr = head;
        for(int i=0;i<index;i++)
            curr = curr->next;

        return curr->val;
    }
    
    void addAtHead(int val) {
        Node* node = new Node(val);

        if(head == NULL){
            head = tail = node;
        }else{
            node->next = head;
            head->prev = node;
            head = node;
        }

        size++;
    }
    
    void addAtTail(int val) {
        Node* node = new Node(val);

        if(tail == NULL){
            head = tail = node;
        }else{
            tail->next = node;
            node->prev = tail;
            tail = node;
        }

        size++;
    }
    
    void addAtIndex(int index, int val) {

        if(index < 0 || index > size) return;

        if(index == 0){
            addAtHead(val);
            return;
        }

        if(index == size){
            addAtTail(val);
            return;
        }

        Node* curr = head;
        for(int i=0;i<index;i++)
            curr = curr->next;

        Node* node = new Node(val);

        node->prev = curr->prev;
        node->next = curr;

        curr->prev->next = node;
        curr->prev = node;

        size++;
    }
    
    void deleteAtIndex(int index) {

        if(index < 0 || index >= size) return;

        Node* curr = head;

        for(int i=0;i<index;i++)
            curr = curr->next;

        if(curr->prev)
            curr->prev->next = curr->next;
        else
            head = curr->next;

        if(curr->next)
            curr->next->prev = curr->prev;
        else
            tail = curr->prev;

        delete curr;
        size--;
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
