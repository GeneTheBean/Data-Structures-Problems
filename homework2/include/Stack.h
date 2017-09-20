    #ifndef STACK_H
    #define STACK_H
    #include <vector>

    using namespace std;

    template <class T>
    class Stack
    {
        public:
            Stack();
            void push(const T& item); //Push an element to the top of the stack
            void pop(); //Pop the top element off of the stack
            T& top(); //Return the element at the top of the stack
            bool isEmpty(); //Returns condition based on whether or not stack is empty

        private:
           std::vector<T> stackVector;
    };

    template<class T>
    Stack<T>::Stack(){}

    template<class T>
    void Stack<T>::push(const T& item){
        stackVector.push_back(item);
    }

    template<class T>
    void Stack<T>::pop(){
        //Check if stack is empty
        if(isEmpty())
            cout<<"No elements to pop."<<endl;

        else stackVector.pop_back();
    }

    template<class T>
    T& Stack<T>::top(){
        //Check if stack is empty
        if(isEmpty())
            cout<<"No elements to pop."<<endl;

        else return stackVector.back();
    }

    template<class T>
    bool Stack<T>::isEmpty(){
        return(stackVector.empty());
    }

    #endif // STACK_H
