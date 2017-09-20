#include <iostream>

using namespace std;

template<class T>
class LinkedList{
    public:
        LinkedList();
        void addNode(T value);
        void deleteNode(T value);
        void printList();
        bool equals(LinkedList<T>);
        int size;
        int getSize();
    private:
        struct node{
            T val;
            node* next;
        };

        node* head;
        node* curr;
        node* temp;
};

template<class T>
    LinkedList<T>::LinkedList(){
        head = NULL;
        curr = NULL;
        temp = NULL;
    }

template<class T>
    void LinkedList<T>::addNode(T value){
        node* n = new node;
        n->val = value;
        n->next = NULL;

        if(head!=NULL){
            curr = head;
            while(curr->next!=NULL)
                curr = curr->next;
            curr->next = n;
        }
        else {
            head = n;
        }
        size++;
}

template<class T>
    void LinkedList<T>::deleteNode(T value){
    node* n = NULL;
    curr = head;
    temp = curr;

    while(curr->next!=NULL && curr->val!=value){
        temp = curr;
        curr = curr->next;
    }

    if(curr->next==NULL && curr->val!=value){
        cout<<"Value was not found"<<endl;
        delete n;
    }

    else{
        n = curr;
        curr = curr->next;
        temp->next = curr;
        delete n;
    }
    size--;
}

template<class T>
    void LinkedList<T>::printList(){
        node* p = head;

        while(p!= NULL){
            cout<<p->val;
            p = p->next;
        }
}

template<class T>
    int LinkedList<T>::getSize(){
        return size;
    }

template<class T>
    bool LinkedList<T>::equals(LinkedList<T> l){
        node* it1;
        node* it2;

        if(getSize() != l.getSize())
            return false;

        while(it1 != NULL){
            if(it1->val != it2->val)
                return false;

            it1 = it1->next;
            it2 = it2->next;
        }

        return true;
    }

int main(){
    LinkedList<int> test;
    test.addNode(4);

    LinkedList<int> test2;
    test.addNode(4);

    cout<<test.equals(test2);
    return 0;
}
