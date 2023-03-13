#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;

// Khai báo các thủ tục sắp xếp
void quickSort(int a[], int low, int high);
void heapSort(int a[], int n);
void mergeSort(int arr[], int l, int r);

int main() {
    const int N = 1e6;
    double a[10][N];

    // Tạo 8 dãy ngẫu nhiên
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = rand();
        }
    }
    // Tạo dãy thứ nhất tăng dần
    for (int j = 0; j < N; j++) {
        a[8][j] = j;
    }
    // Tạo dãy thứ hai giảm dần
    for (int j = 0; j < N; j++) {
        a[9][j] = N - j;
    }
    // Sắp xếp dãy thứ hai giảm dần
    sort(a[9], a[9] + N, greater<double>());

    // Đo thời gian chạy của 4 thuật toán sắp xếp
    cout << "Thoi gian chay QuickSort: ";
    auto startQuickSort = chrono::high_resolution_clock::now();
    for (int i = 0; i < 10; i++) {
        quickSort(a[i], 0, N - 1);
    }
    auto stopQuickSort = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsedQuickSort = stopQuickSort - startQuickSort;
    cout << elapsedQuickSort.count() << " ms" << endl;

    cout << "Thoi gian chay HeapSort: ";
    auto startHeapSort = chrono::high_resolution_clock::now();
    for (int i = 0; i < 10; i++) {
        heapSort(a[i], N);
    }
    auto stopHeapSort = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsedHeapSort = stopHeapSort - startHeapSort;
    cout << elapsedHeapSort.count() << " ms" << endl;

    cout << "Thoi gian chay MergeSort: ";
    auto startMergeSort = chrono::high_resolution_clock::now();
    for (int i = 0; i < 10; i++) {
        mergeSort(a[i], 0, N - 1);
    }
    auto stopMergeSort = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsedMergeSort = stopMergeSort - startMergeSort;
    cout << elapsedMergeSort.count() << " ms" << endl;

    cout << "Thoi gian chay sort (C++ STL): ";
    auto startSort = chrono::high_resolution_clock::now();
    for (int i = 0; i < 10; i++) {
        sort(a[i], a[i] + N);
    }
    auto stopSort = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsedSort = stopSort - startSort;
    cout << elapsedSort.count() << " ms" << endl;

    return 0;
}
