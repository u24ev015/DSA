class BrowserHistory {
public:
    struct Node{
        Node* next;
        Node* prev;
        string data;
        Node(string x)
        {
            data=x;
            prev=NULL;
            next=NULL;
        } 
    };
    Node* head;
    Node* tail;
    BrowserHistory(string homepage) {
    head=new Node(homepage);
    tail=head;   
    }
    
    void visit(string url) {
    Node* newnode=new Node(url);
    tail->next=newnode;
    newnode->prev=tail;
    newnode->next=NULL;
    tail=newnode;    
    }
    
    string back(int steps) {
    int cnt=steps;
    while(cnt!=0)
    {
    if(tail->prev==NULL)
    return tail->data;
    Node* temp=tail;
    tail=tail->prev;
    cnt--;
    }
    return tail->data;    
    }
    
    string forward(int steps) {
    int cnt=steps;
    while(cnt!=0)
    {
    if(tail->next==NULL)
    return tail->data;
    tail=tail->next;
    cnt--;
    }
    return tail->data;     
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
