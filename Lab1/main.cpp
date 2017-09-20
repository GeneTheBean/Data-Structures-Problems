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
        T* array; //Used to store the values of a vector of T values
        unsigned int vec_size; //Keeps track of the number of elements in the vector
        unsigned int vec_capacity; //Keeps track of the number of elements the vector can store
};

//Set default size and capacity for vector and dynamially allocates a new array of set capacity
template <class T>
Vector<T>::Vector(){
    vec_size = 0;
    vec_capacity = 1;
    array = new T[vec_capacity];
}

//Set the array size to the amount of elements to copy, dynamically allocates an array
//runs a loop to set n copies of those values
template <class T>
Vector<T>::Vector(int n, const T& val){
    vec_size = n;
    vec_capacity = vec_size;
    array = new T[vec_capacity];
    for(int i = 0;i<vec_size;i++)
        array[i] = val;
}

//Cycles through the passed vectors elements while copying them into a dynamically allocated array
template <class T>
Vector<T>::Vector(const Vector<T>& v){
    vec_capacity = v.vec_capacity;
    vec_size = v.vec_size;
    array = new T[vec_capacity];
    for(int i=0;i<vec_size;i++){
        array[i] = v.array[i];
    }
}

//Dumps memory allocated for the vectory
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

//Checks to see if there is enough capacity to add a new element, if not call allocate() to resize the vector
//Sets the next element of the back of the vector to passed value and increments the its size
template <class T>
void Vector<T>::push_back(const T& elt){
    if(size()+1>vec_capacity)
        allocate();
    array[size()] = elt;
    vec_size++;
}

//Sets the element at the back of the array to the next index(which is undefined)
template <class T>
void Vector<T>::pop_back(){
    if(empty())
    cout<<"No elements to pop."<<endl;

    else{
        if(size()<vec_capacity/2)
            deallocate();

        array[size()-1] = array[size()];
        vec_size--;
    }
}

//Checks to see if the position is valid to the vector and returns the element at the passed position
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

//Check to see if theres room in the vector to insert an element, if not allocate memory for a resizing
//Insert the element at the position and moves everything over one index to the right. Increment the size.
template <class T>
void Vector<T>::insert (const T& elt, int pos){
    if(size()+1>vec_capacity)
        allocate();

    for(int i=size();i>pos;i--)
        array[i]=array[i-1];
    array[pos] = elt;
    vec_size++;
}

//Check to see if the position in the vector is valid
//Checks to see if there is uneeded extra capcity to deallocate
//For loop starts from the position and sets each value equal to the next index until it hits the last element
//Decrement the vector size to keep count
//Set the value of the last element to the next index of that element(which is undefined)
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
    array[size()] = array[size()+1];
}

//Check to see if the position in the vector is valid
//For loop starts from pos1 and calls erase pos2 times, which individually deletes each element and checks boundaries
template <class T>
void Vector<T>:: erase (int pos1, int pos2){
    if(pos1<0 || pos1>size() || pos2<0 || pos2>=size() || pos2<pos1)
        cout<<"Deletion range from position "<<pos1<<" to "<<pos2<< " is invalid."<<endl;
    else{
        int h = pos1;
        for(int i=pos1;i<pos2+1;i++){
            erase(h);
        }
    }
}

//Checks to see if the vector is equal to the passed vector
//Deallocates the memory used for the pointer(array) and dynamically allocates a new one
//Loops through the array to copy over elements from passed vector and returns it
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

//Acts as a subscript
template <class T>
T& Vector<T>::operator[](int n){
    return array[n];
}

//Prints all of the elements in the vector by looping through the array
template <class T>
void Vector<T>::print(){
    cout<<"Elements in vector: ";

    for(int i=0;i<size();i++){
    cout<<array[i]<<" ";
    }

    cout<<": Vector Size: "<<vec_size<<" Vector Capacity: "<<vec_capacity<<endl;
}

//Sequentially runs through every function defined in the Vector class
int main()
{
    Vector <double> b(5, 2.45);
    Vector <double> a(b);
    cout<<"Size of a: "<<a.size()<<endl;
    b.push_back(4);
    a.pop_back();
    cout<<"The element in position 2 of vector a is "<<a.at(2)<<endl;
    cout<<"The element at the front of vector b is "<<b.front()<<endl;
    cout<<"The element at the back of vector b is "<<b.back()<<endl;
    if(a.empty()) cout<<"vector a is empty."<<endl; else cout<<"Vector a is not empty."<<endl;
    a.insert(12.4,1);
    b.erase(0);
    a.erase(0,3);
    Vector <double> c = a;
    cout<<"c[0] = "<<c[0]<<endl;
    cout<<"a "; a.print();
    cout<<"b "; b.print();
    cout<<"c "; c.print();

return 0;
}
