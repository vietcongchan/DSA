#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    //Find largest among root, left child and right child of father
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[largest] < arr[left]) largest = left;
    if (right < n && arr[largest] < arr[right]) largest = right;

    //check is largest change, if change we will swap root with it child
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    //Build max heap
    for(int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);

    //heapsort
    for(int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
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
    heapSort(arr, n);
    /*/////*/

    //output
    cout << "Arr is sorted (greater): ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
    //endOutput
}
