#ifndef STACK_A_H
#define STACK_A_H

template <class T>
class Stack_A
{
    public:
        Stack_A();
        void push(const T& item); //Push an element to the top of the stack
        void pop(); //Pop the top element off of the stack
        T& top(); //Return the element at the top of the stack
        bool isEmpty(); //Returns condition based on whether or not stack is empty
    protected:
    private:
        unsigned int size(); //returns the size of the array
        void allocate(); //allocates memory for new array (expand)
        void deallocate(); //deallocates memory for new array (shrink)

        unsigned int arr_size;
        unsigned int arr_capacity;
        T* array;
};

template <class T>
Stack_A<T>::Stack_A(){
    arr_size = 0;
    arr_capacity = 1;
    array = new T[arr_capacity];
}

//Checks to see if there is enough capacity to add a new element, if not call allocate() to resize the array
//Sets the top element of the stack to passed value and increments array size
template <class T>
void Stack_A<T>::push(const T& item){
    if(size()+1>arr_capacity)
        allocate();
    array[size()] = item;
    arr_size++;
}

template <class T>
void Stack_A<T>::pop(){
    if(isEmpty())
        cout<<"No elements to pop."<<endl;

    //Deallocates memory to shrink array if there is extra storage
    else{
        if(size()<arr_capacity/2)
            deallocate();

        arr_size--;
    }
}

template <class T>
T& Stack_A<T>::top(){
    // Checks to see if stack is empty
    if(isEmpty())
        cout<<"No elements to pop."<<endl;

    else return array[size()-1];
}

template<class T>
bool Stack_A<T>::isEmpty(){
    return (size() == 0);
}

//Uses a new pointer to allocate memory for a new array and copies values from old
template <class T>
void Stack_A<T>::allocate(){
    arr_capacity = size()*2;
    T* temp = new T[arr_capacity];
    for(int i = 0;i<size();i++){
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
}

//Uses a new pointer to deallocate memory for a new array and copies values from old
template <class T>
void Stack_A<T>::deallocate(){
      arr_capacity/=2;
    T* temp = new T[arr_capacity];
    for(int i = 0;i<size();i++){
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
}

template <class T>
unsigned int Stack_A<T>::size(){
    return arr_size;
}

#endif // STACK_A_H
