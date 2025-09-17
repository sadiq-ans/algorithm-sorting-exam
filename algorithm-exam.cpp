#include <iostream>

using namespace std;

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Selection Sort implementation
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
}

// Merge function used in Merge Sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

// Merge Sort implementation
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Linear Search implementation
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++)
        if (arr[i] == target)
            return i;
    return -1;
}

// Binary Search implementation
int binarySearch(int arr[], int size, int target) {
    int l = 0, r = size - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return -1;
}

int main() {
    int original_array[] = {64, 25, 12, 22, 11, 90, 45, 33};
    int size = sizeof(original_array) / sizeof(original_array[0]);
    int choice;
    int target;
    int result;

    while (true) {
        cout << "\n--- Main Menu ---" << endl;
        cout << "1. Run Selection Sort" << endl;
        cout << "2. Run Merge Sort" << endl;
        cout << "3. Run Linear Search" << endl;
        cout << "4. Run Binary Search" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice) {
            case 1: {
                int arr_copy[size];
                for (int i = 0; i < size; i++)
                    arr_copy[i] = original_array[i];

                cout << "Original array: ";
                printArray(arr_copy, size);

                selectionSort(arr_copy, size);

                cout << "Array after Selection Sort: ";
                printArray(arr_copy, size);
                break;
            }

            case 2: {
                int arr_copy[size];
                for (int i = 0; i < size; i++)
                    arr_copy[i] = original_array[i];

                cout << "Original array: ";
                printArray(arr_copy, size);

                mergeSort(arr_copy, 0, size - 1);

                cout << "Array after Merge Sort: ";
                printArray(arr_copy, size);
                break;
            }

            case 3: {
                cout << "Enter a number to search for: ";
                cin >> target;

                result = linearSearch(original_array, size, target);

                if (result != -1)
                    cout << "Element " << target << " found at index " << result << endl;
                else
                    cout << "Element " << target << " not found." << endl;
                break;
            }

            case 4: {
                cout << "Note: Binary Search requires a sorted array." << endl;

                int sorted_copy[size];
                for (int i = 0; i < size; i++)
                    sorted_copy[i] = original_array[i];

                mergeSort(sorted_copy, 0, size - 1);

                cout << "Sorted array: ";
                printArray(sorted_copy, size);

                cout << "Enter a number to search for: ";
                cin >> target;

                result = binarySearch(sorted_copy, size, target);

                if (result != -1)
                    cout << "Element " << target << " found at index " << result << endl;
                else
                    cout << "Element " << target << " not found." << endl;

                break;
            }

            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice. Please enter a number from 1 to 5." << endl;
                break;
        }
    }

    return 0;
}
