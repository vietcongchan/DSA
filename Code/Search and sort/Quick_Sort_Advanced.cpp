#include <iostream>

using namespace std;

int Partition(int arr[], int left, int right) {
    int pivot = right;
    int j = left - 1;
    for (int i = left; i < right; i++)
        if (arr[i] <= arr[pivot]) {
            j++;
            swap(arr[i], arr[j]);
    }
    swap(arr[j+1], arr[pivot]);
    return j + 1;
}

void Quick_Sort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = Partition(arr, left, right);
        Quick_Sort(arr, left, pivot - 1);
        Quick_Sort(arr, pivot + 1, right);
    }
}

int main() {
    int n;
    cout << "N = ";
    cin >> n;
    int arr[n];
    cout << "Arr:\n";
    for(int i = 0; i < n; i++) {
        cout << "A["<<i<<"] = ";
        cin >> arr[i];
    }
    //
    Quick_Sort(arr, 0, n - 1);
    //
    cout << "Arr is sorted: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
