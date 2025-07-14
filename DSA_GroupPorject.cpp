#include<iostream>
#include<cstdlib>
#include<ctime>
#include<chrono>

using namespace std;
using namespace chrono;


//For Generating Random Number upto 1000
void generateRandomNumbers(int arr[], int n) {
    srand(time(0));
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
}

void displayArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Merge Sort
void merge(int arr[], int st, int mid, int end) {
    int temp[end - st + 1];
    int i = st, j = mid + 1, idx = 0;

    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j]) {
            temp[idx++] = arr[i++];
        } else {
            temp[idx++] = arr[j++];
        }
    }

    while(i <= mid) {
        temp[idx++] = arr[i++];
    }

    while(j <= end) {
        temp[idx++] = arr[j++];
    }

    for(int i = 0; i < end - st + 1; i++) {
        arr[st + i] = temp[i];
    }
}

void mergeSort(int arr[], int st, int end) {
    if(st < end) {
        int mid = st + (end - st) / 2;
        mergeSort(arr, st, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, st, mid, end);
    }
}

// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Binary Search
int binarySearch(int arr[], int size, int tar) {
    int st = 0, end = size - 1;
    while(st <= end) {
        int mid = (st + end) / 2;
        if(tar > arr[mid]) {
            st = mid + 1;
        } else if(tar < arr[mid]) {
            end = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

// Exponential Search
int exponentialSearch(int arr[], int n, int target) {
    if(arr[0] == target) return 0;

    int i = 1;
    while(i < n && arr[i] <= target) {
        i *= 2;
    }

    int left = i / 2;
    int right = min(i, n - 1);

    while(left <= right) {
        int mid = left + (right - left) / 2;    
        if(arr[mid] == target) {
            return mid;
        } else if(arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n, target;
    cout << "========== Random Number Generator ==========\n";
    cout << "Enter the number of random integers to generate: ";
    cin >> n;

    if(n <= 0) {
        cout << "Please enter a positive number." << endl;
        return 1;
    }

    int* arr = new int[n];
    generateRandomNumbers(arr, n);
    cout << "\nGenerated Numbers:\n";
    displayArray(arr, n);

    // Create copies for each sorting algorithm
    int* numbersForMergeSort = new int[n];
    int* numbersForQuickSort = new int[n];
    for(int i = 0; i < n; i++) {
        numbersForMergeSort[i] = arr[i];
        numbersForQuickSort[i] = arr[i];
    }

    cout << "\n========== Sorting Phase ==========";

    // Merge Sort
    auto start = high_resolution_clock::now();
    mergeSort(numbersForMergeSort, 0, n - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "\n[Merge Sort]\nSorted Array:\n";
    displayArray(numbersForMergeSort, n);
    cout << "Time taken: " << duration.count() << " nanoseconds\n";

    // Quick Sort
    start = high_resolution_clock::now();
    quickSort(numbersForQuickSort, 0, n - 1);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "\n[Quick Sort]\nSorted Array:\n";
    displayArray(numbersForQuickSort, n);
    cout << "Time taken: " << duration.count() << " nanoseconds\n";

    cout << "\n========== Searching Phase ==========\n";
    cout << "Enter a number to search: ";
    cin >> target;

    // Binary Search
    start = high_resolution_clock::now();
    int binaryResult = binarySearch(numbersForMergeSort, n, target);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "\n[Binary Search]\n";
    if(binaryResult != -1) {
        cout << "Number found at index: " << binaryResult << endl;
    } else {
        cout << "Number not found.\n";
    }
    cout << "Time taken: " << duration.count() << " nanoseconds\n";

    // Exponential Search
    start = high_resolution_clock::now();
    int exponentialResult = exponentialSearch(numbersForMergeSort, n, target);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "\n[Exponential Search]\n";
    if(exponentialResult != -1) {
        cout << " Number found at index: " << exponentialResult << endl;
    } else {
        cout << " Number not found.\n";
    }
    cout << "Time taken: " << duration.count() << " nanoseconds\n";

    cout << "========== Program Completed ==========";

    // Clean up
    delete[] arr;
    delete[] numbersForMergeSort;
    delete[] numbersForQuickSort;

    return 0;
}


