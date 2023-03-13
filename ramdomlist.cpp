#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6;
double a[10][N];

int main() {
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
    // In dãy thứ nhất và hai
    cout << "Dãy tăng dần: ";
    for (int j = 0; j < N; j++) {
        cout << a[8][j] << " ";
    }
    cout << endl << "Dãy giảm dần: ";
    for (int j = 0; j < N; j++) {
        cout << a[9][j] << " ";
    }
    cout << endl;
    return 0;
}
