#include <iostream>

using namespace std;

int main()
{
    MyList l;

    return 0;
}

// C++
template <typename E>
class ListNode {
    public:
        E data;
        ListNode<E> *next;
        ListNode(E& item, ListNode<E> *ptr = NULL): data(item), next(ptr) {}
};

template <typename E>
class MyList {

    public:
        addNode(E data){
            ListNode<E> =
            if(size == 0)
                head =
        }

    private:
        ListNode<E> *head, *tail;
        int size = 0;
};
