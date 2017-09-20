#include <iostream>
#include <string>


using namespace std;
void bubbleSort(int *, int);
void selectionSort(int *, int);
void insertionSort(int *, int);
void printArray(int *, int);

const int CONST_SIZE = 10;
int main(){
    int arr[CONST_SIZE] = {44,15,39,55,64,24,6,76,85,26};
    insertionSort(arr, CONST_SIZE);
    printArray(arr, CONST_SIZE);
    return 0;
}

void bubbleSort(int *a, int size){
    bool swapped;
    for(int i = 0;i < size-1;i++){
        swapped = false;
        for(int j = 0;j < size-1;j++){
            if(a[j]>a[j+1]){
                int temp = a[j+1];
                swap(a[j],a[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
    return;
}

void selectionSort(int *a, int size){
    int min;
    for(int i = 0;i < size-1;i++){
        min = i;
        for(int j = i+1;j < size;j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        if(min!=i){
            swap(a[i], a[min]);
        }
    }
    return;
}

void insertionSort(int* a, int size){
    for(int i = 1;i < size;i++){
        for(int j = i;j>0;j--){
            if(a[j]<a[j-1])
                swap(a[j], a[j-1]);
            else break;
        }
    }
    return;
}

void printArray(int *a, int size){
    for(int i = 0;i < size; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return;
}

