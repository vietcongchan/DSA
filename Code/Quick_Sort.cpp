#include <iostream>
using namespace std;

void quicksort(int a[], int left, int right) {
    int element_mid = arr[(left + right) / 2];
    int i = left, j = right;

    while (i < j) {
        while (arr[i] < element_mid) i = i + 1;
        while (arr[j] > element_mid) j = j - 1;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i = i + 1;
            j = j - 1;
        }
    }
    if (i < right) quicksort(arr, i, right);
    if (j > left) quicksort(arr, left, j);
}

int main() {
    //input
    int n;
    cout << "Input N = ";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cout << "A[" <<i<< "] = ";
        cin >> arr[i];
    }
    //endInput

    /*/////*/
    quicksort(arr, 0, n - 1);
    /*/////*/

    //output
    cout << "Arr is sorted (greater): ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
    //endOutput
}
