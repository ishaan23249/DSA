// Ishaan Shekhar 
// DSA, Lab - 10
// ROLL NO. 2023249

#include <iostream>
#include <algorithm>
using namespace std;
// Creating a Heap Class 
class Heap {
    public:
     int arr[100];
     int size = 0;

     Heap() {
        arr[0] = -1;
        size = 0;
     }

// Insert function. 
void insert(int val){
        size = size+1;
        int index = size;
        arr[index] = val;
        while (index > 1){
            int parent = index/2;
            if (arr[parent] > arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else {
                return;
            }
        }
};

// Deletion of root in Heap. 
void deletefromHeap(int val){
        if (size == 0){
            cout << "Nothing to Delete" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i<size){
            int leftIndex = 2*i;
            int rightIndex = 2*i + 1;
            if (leftIndex < size && arr[i] > arr[leftIndex]){
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] > arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else {
                return ; 
            }
            
        }
}

// Function to print elements of Heap 
void print() {
        for (int i = 1; i<=size; i++){
            cout << arr[i] << " "; 
        }cout << endl;
}
};

// Min - Heapify function. 
void heapify_func(int arr[], int n, int i){
        int smallest = i;
        int left = 2*i+1;
        int right = 2*i+2;

        if (left < n && arr[left] < arr[smallest]){
            smallest = left;
        }
        if (right < n && arr[right] < arr[smallest]){
            smallest = right;
        }

        if (smallest != i){
            swap(arr[smallest], arr[i]);
            heapify_func(arr, n, smallest);
        }
}

// Heapsort function.
void heapsort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify_func(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify_func(arr, i, 0);
        }
    reverse(arr, arr+6);
    }
}

void extract_min(int arr[], int n){
    if (n == 1){
        int a = arr[0];
        return;
    }
    int root = arr[0];
    arr[0] = arr[n-1];
    heapify_func(arr, n-1, 0);
}
int main () {
    // Insert, Delete, Print Heap 
    Heap h;
    h.insert(40);
    h.insert(50);
    h.insert(90);
    h.insert(20);
    h.insert(60);
    h.insert(100);
    h.deletefromHeap(100);
    h.print();


    int arr[6] = {11,10,100,5,9,45};
    for (int i = 0; i<6; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // Heapify function
    for (int i = 2; i>=0; i--){
        heapify_func(arr, 6, i);
    }

    // Heapsort function 
    heapsort(arr, 6);
    for (int i = 0; i<6; i++){
        cout << arr[i] << " ";
    }cout << endl;

    // Extract Min Function. 
    extract_min(arr, 6);
    for (int i = 0; i<5; i++){
        cout << arr[i] << " ";
    }
}
