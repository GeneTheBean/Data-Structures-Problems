#include <iostream>
using namespace std;

template <class T>
class Vector
{
    public:
        Vector(); // construct empty vector
        Vector(int n, const T& val); // construct vector with n copies of val
        Vector(const Vector<T>& v); // construct copy of v
        ~Vector(); // deletes all memory allocated for the vector
        void allocate(); // allocates new memory to resize the vector
        void deallocate(); //deallocates memory to resize the vector
        unsigned int size(); // returns the current size of the vector
        void push_back(const T& elt); // insert element elt at end of vector
        void pop_back(); //delete last element
        T& at(int pos); // return reference to element at position pos if pos is valid
        T& front(); //return reference to first element
        T& back(); //return refrence to last element
        bool empty(); // return true if vector is empty
        void insert (const T& elt, int pos); // insert element elt at position pos
        void erase (int pos); // delete element at position pos
        void erase (int pos1, int pos2); // delete elements from pos1 to pos2 (inclusive)
        Vector<T>& operator=(const Vector& v); // assignment operator
        T& operator[](int n); // returns reference to element at position n
        void print(); // prints all vector elements

    protected:
    private:
        T* array;
        unsigned int vec_size;
        unsigned int vec_capacity;
};

template <class T>
Vector<T>::Vector(){
    vec_size = 0;
    vec_capacity = 1;
    array = new T[vec_capacity];
}

template <class T>
Vector<T>::Vector(int n, const T& val){
    vec_size = n;
    vec_capacity = vec_size;
    array = new T[vec_capacity];
    for(int i = 0;i<vec_size;i++)
        array[i] = val;
}

template <class T>
Vector<T>::Vector(const Vector<T>& v){
    vec_capacity = v.vec_capacity;
    vec_size = v.vec_size;
    array = new T[vec_capacity];
    for(int i=0;i<vec_size;i++){
        array[i] = v.array[i];
    }
}

template <class T>
Vector<T>::~Vector(){
delete[] array;
}

//Uses a new pointer to allocate memory for a new array and copies values from old
template <class T>
void Vector<T>::allocate(){
    vec_capacity = size()*2;
    T* temp = new T[vec_capacity];
    for(int i = 0;i<size();i++){
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
}

//Uses a new pointer to allocate memory for a new array and copies values from old
//The goal is to shrink the capacity size to release the extra memory when the capacity is too large
template <class T>
void Vector<T>::deallocate(){
      vec_capacity/=2;
    T* temp = new T[vec_capacity];
    for(int i = 0;i<size();i++){
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
}

template <class T>
unsigned int Vector<T>::size(){
    return vec_size;
}

template <class T>
void Vector<T>::push_back(const T& elt){
    if(size()+1>vec_capacity)
        allocate();
    array[size()] = elt;
    vec_size++;
}

template <class T>
void Vector<T>::pop_back(){
    if(size()==0)
    cout<<"No elements to pop.";

    else{
    array[size()-1] = array[size()];
    vec_size--;
    }
}

template <class T>
T& Vector<T>::at(int pos){
    if(pos<0 || pos>size())
        cout<<"Element in position: "<<pos<<" is out of scope.";
    else return array[pos];
}

template <class T>
T& Vector<T>::front(){
    return array[0];
}

template <class T>
T& Vector<T>::back(){
    return array[size()-1];
}

template <class T>
bool Vector<T>::empty(){
    return (size()==0);
}

template <class T>
void Vector<T>::insert (const T& elt, int pos){
    if(size()+1>vec_capacity)
        allocate();
    for(int i=size();i>pos;i--)
        array[i]=array[i-1];
    array[pos] = elt;
    vec_size++;
}

template <class T>
void Vector<T>::erase (int pos){
    if(pos<0 || pos>size())
        cout<<"Element in position: "<<pos<<" is out of scope.";
    else if(size()<vec_capacity/2)
        deallocate();

    for(int i=pos;i<size()-1;i++){
        array[i] = array[i+1];
    }
    vec_size--;
    array[size()] = 0;
}

template <class T>
void Vector<T>:: erase (int pos1, int pos2){
    if(pos1<0 || pos1>size() || pos2<0 || pos2>size() || pos2<pos1)
        cout<<"Deletion range from position "<<pos1<<" to "<<pos2<< " is invalid.";
    else{
        int h = pos1;
        for(int i=pos1;i<pos2+1;i++){
            erase(h);
        }
    }
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector& v){
    if(this!=&v){
        vec_capacity = v.vec_capacity;
        vec_size = v.vec_size;
        delete[] array;
        array = new T[vec_capacity];
        for(int i=0;i<vec_size;i++)
            array[i] = v.array[i];
        return *this;
    }
}

template <class T>
T& Vector<T>::operator[](int n){
    return array[n];
}

template <class T>
void Vector<T>::print(){
    cout<<"Elements in vector: ";

    for(int i=0;i<size();i++){
    cout<<array[i]<<" ";
    }

    cout<<": Vector Size: "<<vec_size<<" Vector Capacity: "<<vec_capacity<<endl;
}

