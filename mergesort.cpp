#include <iostream>
using namespace std;

// Merge 2 mảng con của arr[].
// Mảng con là arr[l..m] và arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Tạo các mảng con
    int L[n1], R[n2];

    // Gán giá trị của arr sang L, R
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Gộp 2 mảng con lại, ban đầu là ít nhất trước
    i = 0; // Chỉ mục ban đầu của mảng con đầu tiên
    j = 0; // Chỉ mục ban đầu của mảng con thứ hai
    k = l; // Chỉ mục ban đầu của mảng trộn
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của L[], nếu có
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của R[], nếu có
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Hàm chính gọi hàm đệ quy MergeSort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Tương đương với (l+r)/2, nhưng tránh tràn số khi l,r lớn
        int m = l + (r - l) / 2;

        // Gọi hàm đệ quy tới khi mảng con chỉ còn một phần tử trở lên
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Gộp 2 mảng con vừa chia
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, arr_size - 1);

    cout << "Dãy sau khi sắp xếp: ";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    return 0;
}
