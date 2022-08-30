#include <iostream>
#include <fstream>
#define size_limit 100

using namespace std;

void datainp(int arr[], int &n) {
    //file input: ifstream Ten_Bien
    ifstream Fi;
    Fi.open("data.inp", ios::in); //open file
    Fi >> n;
    for (int i = 0; i < n; i++) Fi >> arr[i];
    Fi.close(); //close file
}

void merge_(int arr[], int left, int mid, int right) {
    int n1 = (mid - left + 1);
    int n2 = right - mid;

    int L[n1];
    int R[n2];
    //khoi tao 2 mang trai phai
    for (int i = 0; i < n1; i++) L[i] = arr[i + left];
    for (int i = 0; i < n2; i++) R[i] = arr[i + mid + 1];
    //swap
    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge_(arr, left, mid, right);
    }
}

void process(int arr[], int n) {
    merge_sort(arr, 0, n - 1);
}

void dataout(int arr[], int n) {
    //file output: ofstream
    ofstream Fo;
    Fo.open("data.out", ios::out);
    Fo << "Array is sorted: ";
    for (int i = 0; i < n; i++) Fo << arr[i] << " ";
}

int main() {
    int n, arr[size_limit];
    datainp(arr, n);
    process(arr, n);
    dataout(arr, n);
}
