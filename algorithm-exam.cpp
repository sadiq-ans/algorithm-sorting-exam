#include <iostream>
#include <vector>

using namespace std;

// class SortingandSearch() {
//     int *arr;
//     int size;

//     Sorting(int size) {
//         this->size = size;
//         this->arr = new int arr[size];
//     }

//     ~Sorting() {
//         delete arr;
//     }
// }

void selectionSort(vector<int> &);

int main() {
    int size;
    
    cout << "Enter length of array : ";
    cin >> size;

    vector<int> arr(size, 0);

    for (int i = 0; i < size; i++) {
        cout << "Enter the array value : ";
        cin >> arr[i];
    }

    cout << "---------------BEFORE----------------" << endl;
        for (int val : arr) {
        cout << val << " ";
    }

    cout << endl;

    selectionSort(arr);

    cout << "---------------AFTER----------------" << endl;
        for (int val : arr) {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}

void selectionSort(vector<int> & arr) {
    
        for (int i = 0; i < arr.size(); i++) { 
        int minIdx = i; 

        for (int j = i + 1; j < arr.size(); j++) { 
            if(arr[minIdx] > arr[j]) {
                minIdx = j;
            }
        }

        if(minIdx != i) {
            int temp = arr[minIdx];
            arr[minIdx] = arr[i];
            arr[i] = temp;
        }
    }
}